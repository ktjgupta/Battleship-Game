#include "ofApp.h"
#include "game-engine.h"

//--------------------------------------------------------------
const int kTileWidth = 72;
const int kTileSep = 5;
const int kTitleWidth = 850;
const int kTitleHeight = 200;
const int kBoardY = 210;


void ofApp::setup(){

	title_img.load("images/battleship_logo.png");
	player_label.load("verdana.ttf", 30);
	enemy_label.load("verdana.ttf", 30);
	game_label.load("verdana.ttf", 100);
	
	enemy_board = getNewBoard();
	player_board = getNewBoard();
	player_won = false;
    enemy_won = false;
	gamesquare myRect;
	vector<vector<gamesquare> > board(kWidth, vector<gamesquare>(kWidth,  myRect));
	p_board = board;
	e_board = board;
	int y = kBoardY;
	for (int i = 0; i < kWidth; i++) {
		int x = 15;
		for (int j = 0; j < kWidth; j++) {
			gamesquare square;
			square.rect.set(x, y, kTileWidth, kTileWidth);
			square.color = ofColor::blue;
			square.name = to_string(i) + to_string(j);
			p_board[i][j] = square;
			x += kTileWidth + kTileSep;
		}
		y += kTileWidth + kTileSep;
	}
	
	y = kBoardY;
	for (int i = 0; i < kWidth; i++) {
		int x = 1140;
		for (int j = 0; j < kWidth; j++) {
			gamesquare square;
			square.rect.set(x, y, kTileWidth, kTileWidth);
			square.color = ofColor::blue;
			square.name = to_string(i) + to_string(j);
			e_board[i][j] = square;
			x += kTileWidth + kTileSep;
		}
		y += kTileWidth + kTileSep;
	}

	for (int i = 0; i < kWidth; i++) {
		for (int j = 0; j < kWidth; j++) {
			std::cout << enemy_board[i][j] << " ";
		}
		std::cout << std::endl;
	}
	player_turn = true;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (!player_won && !enemy_won) {
		if (player_turn) {
			for (int i = 0; i < kWidth; i++) {
				for (int j = 0; j < kWidth; j++) {
					if (ofGetMousePressed() && e_board[i][j].rect.inside(ofGetMouseX(), ofGetMouseY())) {
						char init_val = enemy_board[i][j];
						char new_val = e_board[i][j].ChangeColor(init_val);
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
			player_board[i][j] = p_board[i][j].ChangeColor(player_board[i][j]);
			player_turn = true;
		}
		player_won = CheckIfWon(enemy_board);
		enemy_won = CheckIfWon(player_board);
	}
	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::white, ofColor::gray);
	ofSetColor(ofColor::white);
	title_img.draw(500, 0, kTitleWidth, kTitleHeight);
	player_label.drawString("Player Board", 10, 200);
	enemy_label.drawString("Enemy Board", 1640, 200);

	
	for (int i = 0; i < kWidth; i++) {
		for (int j = 0; j < kWidth; j++) {
			ofSetColor(p_board[i][j].color);
			ofDrawRectangle(p_board[i][j].rect);
		}
	}

	for (int i = 0; i < kWidth; i++) {
		for (int j = 0; j < kWidth; j++) {
			ofSetColor(e_board[i][j].color);
			ofDrawRectangle(e_board[i][j].rect);
		}
	}

	if (player_won) {
		ofSetColor(ofColor::red);
		game_label.drawString("YOU WIN!", 500, 500);
	}
	if (enemy_won) {
		ofSetColor(ofColor::red);
		game_label.drawString("YOU LOSE!", 500, 500);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
