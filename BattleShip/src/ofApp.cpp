#include "ofApp.h"
#include "game-engine.h"

#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;

//--------------------------------------------------------------
const int kTitleWidth = 850;
const int kTitleHeight = 200;
const int kBoardY = 210;
const int kWidth = 10;


void ofApp::setup(){

	title_img.load("images/battleship_logo.png");
	player_label.load("verdana.ttf", 30);
	enemy_label.load("verdana.ttf", 30);
	game_label.load("verdana.ttf", 100);
	size_label.load("verdana.ttf", 50);
	hit_sound.load("sounds/explosion.mp3");
	back_sound.load("sounds/BGM.mp3");
	back_sound.setLoop(true);
	back_sound.setVolume(0.3);
	back_sound.play();
	enemy_board = getNewBoard();
	vector<vector<char> > board(kWidth, vector<char>(kWidth, '_'));
	player_board = board;
	player_won = false;
    enemy_won = false;
	p_board.MakeBoard(15, kBoardY);
	e_board.MakeBoard(1140, kBoardY);
	
	player_turn = true;
	
	destroyer.size = 2;
	destroyer.rect.set(900, 210, 100, 120);
	submarine.size = 3;
	submarine.rect.set(900, 340, 100, 160);
	cruiser.size = 3;
	cruiser.rect.set(900, 510, 100, 160);
	battleship.size = 4;
	battleship.rect.set(1010, 210, 100, 200);
	carrier.size = 5;
	carrier.rect.set(1010, 420, 100, 250);

	ships.push_back(destroyer);
	ships.push_back(submarine);
	ships.push_back(cruiser);
	ships.push_back(battleship);
	ships.push_back(carrier);
	size_text = "";
	init_set = false;
	init_x = 0;
	init_y = 0;
	fin_x = 0;
	fin_y = 0; 
	size = 0;
	ship_index = 0;
	current_state = SHIP_UNCLICKED;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (current_state  == SHIP_UNCLICKED) {
		ClickShip();
	}
	if (current_state == PICK_COORD) {
		PickCoordinates();
	}
	if (current_state == PLACE_SHIP) {
		ShipPlacement();
	}
	if (current_state == PLAY) {
		if (!player_won && !enemy_won) {
			if (player_turn) {
				PlayerMove();
			}
			else {
				EnemyMove();
			}
			player_won = CheckIfWon(enemy_board);
			enemy_won = CheckIfWon(player_board);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::white, ofColor::gray);
	ofSetColor(ofColor::white);
	title_img.draw(500, 0, kTitleWidth, kTitleHeight);
	player_label.drawString("Player Board", 10, 200);
	p_board.draw();
	if (current_state != PLAY) {		
		for (Ship ship : ships) {
			ofSetColor(ofColor::orange);
			ofDrawRectangle(ship.rect);
		}
		ofSetColor(ofColor::black);
		size_label.drawString(size_text, 800, 800);
	} else {
		ofSetColor(ofColor::white);
		enemy_label.drawString("Enemy Board", 1640, 200);
		e_board.draw();
	}
	
	if (player_won) {
		ofSetColor(ofColor::black);
		game_label.drawString("YOU WIN!", 600, 600);
	}
	if (enemy_won) {
		ofSetColor(ofColor::black);
		game_label.drawString("YOU LOSE!", 600, 600);
	}

}

/*Method that allows the player to make their move*/
void ofApp::PlayerMove() {
	for (int i = 0; i < kWidth; i++) {
		for (int j = 0; j < kWidth; j++) {
			if (ofGetMousePressed() && e_board.display_board[i][j].rect.inside(ofGetMouseX(), ofGetMouseY())) {
				char init_val = enemy_board[i][j];
				char new_val = e_board.display_board[i][j].ChangeColor(init_val, hit_sound);
				enemy_board[i][j] = new_val;
				if (new_val != init_val) {
					player_turn = false;
				}
			}
		}
	}
}

/*Method that allows the enemy to make theie move*/
void ofApp::EnemyMove() {
	int i, j;
	std::tie(i, j) = CalculateEnemyMove();
	player_board[i][j] = p_board.display_board[i][j].ChangeColor(player_board[i][j], hit_sound);
	player_turn = true;
}

/*Method that validates and places each ship*/
void ofApp::ShipPlacement() {
	int og_x = init_x;
	int og_y = init_y;
	SwapCoords(init_x, init_y, fin_x, fin_y);
	char orient = ValidatePlacement(size, init_x, init_y, fin_x, fin_y, player_board);
	if (orient == '_') {
		p_board.display_board[og_x][og_y].color = ofColor::blue;
	}
	else {
		player_board = PlaceShip(player_board, orient, init_x, init_y, size, p_board);
		ships.erase(ships.begin() + ship_index);
	}
	current_state = SHIP_UNCLICKED;
	size_text = "";
	if (ships.size() == 0) {
		current_state = PLAY;
	}
	init_set = false;
	sleep_for(milliseconds(500));
}

/*Method that picks coordinates to place ships*/
void ofApp::PickCoordinates() {
	for (int i = 0; i < kWidth; i++) {
		for (int j = 0; j < kWidth; j++) {
			if (ofGetMousePressed() && p_board.display_board[i][j].rect.inside(ofGetMouseX(), ofGetMouseY())) {
				string coordinate = p_board.display_board[i][j].name;
				if (!init_set) {
					p_board.display_board[i][j].color = ofColor::purple;
					init_x = coordinate[0] - '0';
					init_y = coordinate[1] - '0';
					init_set = true;
					sleep_for(milliseconds(500));
				}
				else {
					fin_x = coordinate[0] - '0';
					fin_y = coordinate[1] - '0';
					current_state = PLACE_SHIP;
				}
			}
		}
	}
}

/*Method that allows the player to click a ship*/
void ofApp::ClickShip() {
	size = 0;
	for (int i = 0; i < ships.size(); i++) {
		if (ofGetMousePressed() && ships[i].rect.inside(ofGetMouseX(), ofGetMouseY())) {
			size = ships[i].size;
			current_state = PICK_COORD;
			size_text = "Ship Size: " + to_string(size);
			ship_index = i;
			break;
		}
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int upper_key = toupper(key);
	if (upper_key == 'R') {
		setup();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
