#include "ofMain.h"
#include "ofApp.h"
#include <stdlib.h> 
#include <map>
#include <iostream>
#include "enemy.h"


//========================================================================


int main( ){


	std::cout << "hello" << std::endl;
	srand(time(NULL));
	
	GenerateRandomBoard();
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}


