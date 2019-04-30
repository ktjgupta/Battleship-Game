#pragma once
#include "ofMain.h"

class GameSquare {
	
	
public:
	ofRectangle rect;
	string name;
	ofColor color;

	char ChangeColor(char val) {
		if (val == 'S') {
			color = ofColor::red;
			return 'H';
		}
		if (val == '_') {
			color = ofColor::gray;
			return 'M';
		}
		return val;
	}

};