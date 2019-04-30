#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxMSAInteractiveObject.h"
#include "GameBoard.h"
#include "Ship.h"

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
		void PlayerMove();
		void ShipPlacement();
		void PickCoordinates();
		void ClickShip();
		void EnemyMove();
		
		ofSoundPlayer hit_sound;
		ofSoundPlayer back_sound;
		GameBoard p_board;
		GameBoard e_board;

		vector<vector<char>> player_board;
		vector<vector<char>> enemy_board;
		bool player_turn;

		ofImage title_img;
		ofTrueTypeFont  player_label;
		ofTrueTypeFont  enemy_label;
		ofTrueTypeFont  game_label;
		ofTrueTypeFont  size_label;

		string size_text;

		enum GameState {
			PLAY,
			SHIP_UNCLICKED,
			PLACE_SHIP,
			PICK_COORD
		};


		bool player_won;
		bool enemy_won;
		vector<Ship> ships;

		Ship destroyer;
		Ship submarine;
		Ship cruiser;
		Ship battleship;
		Ship carrier;

		bool init_set;
		int init_x, init_y, fin_x, fin_y;
		int ship_index;
		int size;
		GameState current_state;

};
