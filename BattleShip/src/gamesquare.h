#pragma once
#include "ofMain.h"

class GameSquare {
	
	
public:
	ofRectangle rect;
	string name;
	ofColor color;

	char ChangeColor(char val, ofSoundPlayer hit_sound) {
		if (val == 'S') {
			color = ofColor::red;
			hit_sound.play();
			return 'H';
		}
		if (val == '_') {
			color = ofColor::gray;
			return 'M';
		}
		return val;
	}

};