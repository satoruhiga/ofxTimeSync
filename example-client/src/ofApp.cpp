#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	client.connect("127.0.0.1", 6666);

	ofSetBackgroundColor(0);
	ofSetWindowShape(320, 75);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	try 
	{
		ofxTimeSync::timestamp_t p = client.getTimestampPhase();
		ofxTimeSync::timestamp_t l = client.getLocalTimestamp();
		ofxTimeSync::timestamp_t t = l + p;
		std::stringstream ss;
		ss << "Port: 6666" << endl;
		ss << "local timestamp: " << ofxTimeSync::to_string(l) << endl;
		ss << "timestamp phase: " << ofxTimeSync::to_string(p) << endl;
		ss << "timestamp: " << ofxTimeSync::to_string(t) << endl;
		
		ofDrawBitmapString(ss.str(), 10, 20);
	}
	catch (dex::ClockException e) {
		cout << e.getMessage() << endl;
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
