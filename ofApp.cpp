#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetColor(39);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	int radius_span = 10;
	ofNoFill();
	for (int radius = ofGetWidth(); radius > radius_span; radius -= radius_span) {

		ofRotate(ofGetFrameNum() * -0.05);
		this->draw_pentagon(radius);
	}

	ofFill();
	this->draw_pentagon(radius_span * 2);
}

//--------------------------------------------------------------
void ofApp::draw_pentagon(int radius) {
	
	int deg_span = 72;
	ofBeginShape();
	for (int deg = 0; deg < 360; deg += deg_span) {

		ofVertex(ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
	}
	ofEndShape(true);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}