#pragma once
#include "ofMain.h"
#include "ofApp.h"

class gamesquare {
	
	
public:
	ofRectangle rect;
	string name;
	ofColor color;

	char ChangeColor(char val) {
		if (ofGetMousePressed() && rect.inside(ofGetMouseX(), ofGetMouseY())) {
			if (val == 'S') {
				color = ofColor::red;
				return 'H';
			}
			if (val == '_') {
				color = ofColor::gray;
				return 'M';
			}
			
		}
		return val;
	}

};