#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup("panel");
	button.addListener(this, &ofApp::ButtonPressed);
	gui.add(button.setup("button"));
	myRect.setWidth(200);
	myRect.setHeight(200);
	//obj.setHeight(300);
	//obj.setWidth(200);

	obj.set(300, 50, 100, 200);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::white, ofColor::gray);
	gui.draw();
	/*
	ofSetColor(0,0,0);
	ofDrawRectangle(myRect);
	if (ofGetMousePressed() && myRect.inside(mouseX, mouseY)) {
		cout << "YAY";
	}
	*/
	if (bIsClicked) {
		ofSetColor(ofColor::yellow);// draw a yellow rectangle when clicked
	}
	else {
		auto x = ofColor::gray;
		ofSetColor(x);
	}

	ofDrawRectangle(myRect);

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
	bIsClicked = myRect.inside(x, y);
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

void ofApp::ButtonPressed() {
	//button.play();
}