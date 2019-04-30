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
	
	for (int i = 0; i < kWidth; i++) {
		for (int j = 0; j < kWidth; j++) {
			std::cout << enemy_board[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	player_turn = true;
	game_start = true;
	
	destroyer.size = 2;
	destroyer.rect.set(1200, 210, 100, 100);
	
	submarine.size = 3;
	submarine.rect.set(1200, 320, 100, 100);

	cruiser.size = 3;
	cruiser.rect.set(1200, 430, 100, 100);

	battleship.size = 4;
	battleship.rect.set(1200, 540, 100, 100);

	carrier.size = 5;
	carrier.rect.set(1200, 650, 100, 100);

	ships.push_back(destroyer);
	ships.push_back(submarine);
	ships.push_back(cruiser);
	ships.push_back(battleship);
	ships.push_back(carrier);
	int y = 205;
	/*
	for (Ship ship : ships) {
		ship.rect.set(1000, y, 20, 20);
		y += 20;
	}
	*/
	ship_clicked = false;
	ready = false;
	init_set = false;
	init_x = 0;
	init_y = 0;
	fin_x = 0;
	fin_y = 0; 
	size = 0;
	init_i = 0;
	init_j = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (game_start) {
		
		if (!ship_clicked) {
			size = 0;
			it = ships.begin();
			for (Ship ship : ships) {
				if (ofGetMousePressed() && ship.rect.inside(ofGetMouseX(), ofGetMouseY())) {
					size = ship.size;
					ship_clicked = true;
					cout << "Ship Size: " << size << endl;
					ship_ptr = ship;
					break;
				}
				++it;
			}
		}
		if (ship_clicked) {
			
			
			if (ready) {
				if (fin_x < init_x) {
					int temp = fin_x;
					fin_x = init_x;
					init_x = temp;
				}
				if (fin_y < init_y) {
					int temp = fin_y;
					fin_y = init_y;
					init_y = temp;
				}
				char orient = ValidatePlacement(size, init_x, init_y, fin_x, fin_y, player_board);
				if (orient == '_') {
					cout << "Invalid" << endl;
					p_board.display_board[init_i][init_j].color = ofColor::blue;
				}
				else {
					cout << "Valid" << endl;
					cout << orient << endl;
					player_board = PlaceShip(player_board, orient, init_x, init_y, size);
					if (orient == 'H') {
						for (int y = 0; y < size; y++) {
							p_board.display_board[init_x][init_y + y].color = ofColor::green;
						}
					}
					else {
						for (int x = 0; x < size; x++) {
							p_board.display_board[init_x + x][init_y].color = ofColor::green;
						}
					}
					for (int i = 0; i < kWidth; i++) {
						for (int j = 0; j < kWidth; j++) {
							std::cout << player_board[i][j] << " ";
						}
						std::cout << std::endl;
					}
					ship_clicked = false;
					ships.erase(it);
				}
				if (ships.size() == 0) {
					game_start = false;
				}
				init_set = false;
				ready = false;
				sleep_for(milliseconds(500));
				/*
				cout << "hfkj" << endl;
				cout << init_x << endl;
				cout << init_y << endl;
				cout << fin_x << endl;
				cout << fin_y << endl;
				*/
			}
			else {
				for (int i = 0; i < kWidth; i++) {
					for (int j = 0; j < kWidth; j++) {
						if (ofGetMousePressed() && p_board.display_board[i][j].rect.inside(ofGetMouseX(), ofGetMouseY())) {
							if (!init_set) {
								string coordinate = p_board.display_board[i][j].name;
								p_board.display_board[i][j].color = ofColor::purple;
								init_i = i;
								init_j = j;
								cout << coordinate << endl;
								init_x = coordinate[0] - '0';
								cout << init_x << endl;
								init_y = coordinate[1] - '0';
								cout << init_y << endl;
								init_set = !init_set;
								
								if (ofGetMousePressed()) {
									cout << "mouse down" << endl;
									sleep_for(milliseconds(500));
								}
							}
							else {
								//cout << "blah";
								string coordinate = p_board.display_board[i][j].name;
								cout << coordinate << endl;
								fin_x = coordinate[0] - '0';
								cout << fin_x << endl;
								fin_y = coordinate[1] - '0';
								cout << fin_y << endl;
								ready = true;


							}
						}
					}
				}
			}			
		}
		
	}
	else {
		if (!player_won && !enemy_won) {
			if (player_turn) {
				for (int i = 0; i < kWidth; i++) {
					for (int j = 0; j < kWidth; j++) {
						if (ofGetMousePressed() && e_board.display_board[i][j].rect.inside(ofGetMouseX(), ofGetMouseY())) {
							char init_val = enemy_board[i][j];
							char new_val = e_board.display_board[i][j].ChangeColor(init_val);
							if (new_val == 'H') {
								hit_sound.play();
							}
							enemy_board[i][j] = new_val;
							if (new_val != init_val) {
								player_turn = false;
							}
						}
					}
				}
			}
			else {
				int i, j;
				std::tie(i, j) = CalculateEnemyMove();
				player_board[i][j] = p_board.display_board[i][j].ChangeColor(player_board[i][j]);
				if (player_board[i][j] == 'H') {
					hit_sound.play();
				}
				player_turn = true;
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
	if (game_start) {		
		for (Ship ship : ships) {
			ofSetColor(ofColor::orange);
			ofDrawRectangle(ship.rect);
		}
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
