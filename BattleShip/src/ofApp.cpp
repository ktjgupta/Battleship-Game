#include "ofApp.h"
#include "game-engine.h"

//--------------------------------------------------------------
const int kTileWidth = 50;
const int kTileSep = 5;


void ofApp::setup(){
	enemy_board = getEnemyBoard();
	gamesquare myRect;
	vector<vector<gamesquare> > board2(kWidth, vector<gamesquare>(kWidth,  myRect));
	board = board2;
	int y = 0;
	for (int i = 0; i < kWidth; i++) {
		int x = 0;
		for (int j = 0; j < kWidth; j++) {
			gamesquare square;
			square.rect.set(x, y, kTileWidth, kTileWidth);
			square.color = ofColor::blue;
			square.name = to_string(i) + to_string(j);
			board[i][j] = square;
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
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < kWidth; i++) {
		for (int j = 0; j < kWidth; j++) {
			enemy_board[i][j] = board[i][j].ChangeColor(enemy_board[i][j]);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::white, ofColor::gray);

	
	for (int i = 0; i < kWidth; i++) {
		for (int j = 0; j < kWidth; j++) {
			ofSetColor(board[i][j].color);
			ofDrawRectangle(board[i][j].rect);
		}
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
