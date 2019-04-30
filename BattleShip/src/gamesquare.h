#pragma once
#include "ofMain.h"

class GameSquare {
	
	
public:
	ofRectangle rect;
	string name;
	ofColor color;

	char ChangeColor(char val, ofSoundPlayer hit_sound);

};