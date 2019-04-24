#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxMSAInteractiveObject.h"
#include "gamesquare.h"

const int kWidth = 10;
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		vector<vector<gamesquare> > p_board;
		vector<vector<gamesquare> > e_board;
		vector<vector<char>> player_board;
		vector<vector<char>> enemy_board;
		bool player_turn;

		ofImage title_img;
		ofTrueTypeFont  player_label;
		ofTrueTypeFont  enemy_label;
		ofTrueTypeFont  game_label;

		bool player_won;
		bool enemy_won;
		

};
