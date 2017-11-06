#include "ofApp.h"

ofVec3f Znormal(0, 0, 1);
ofVec3f Xnormal(1, 0, 0);
ofVec3f Ynormal(1, 0, 1);

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetFrameRate(60);
	ofSetCircleResolution(50);
	ofNoFill();
	
    basePoint.set(0, 0, 0);
    angle = 0;
	size = 200;
	stepDown = 20;
	height = 20;
	
	numRings = 8;
	hideWireframe = false;
	
	for (int i = 0; i < numRings; i++) {
		
		ofVec3f rotation;
		if (i == 0)
		{
			rotation.set(0,0,0);
		} else if (i >= 1)
		{
			rotation.set(ofRandom(0,90),0,0);
		}
		
		rotations.push_back(rotation);
		
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	for (int i = 0; i < rotations.size(); i++) {
		rotations[i].y += 0.5;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
    ofSetColor(255);
	
	size = 200;
	cam.begin();
	
		drawStructure();
		popMatrices();
	
	cam.end();
	
	
	
	// draw fps
	ofSetColor(0);
	ofDrawBitmapString
	(
	 "fps :: " + ofToString(ofGetFrameRate(), 2) + "\n\n",
	 20,
	 20
	 );
	
}

ofMatrix4x4 ofApp::returnMatrix(ofVec3f rot){
	
	ofQuaternion q;
	
	if (rot.x != 0.0f) q *= ofQuaternion(rot.x, ofVec3f(1.0f, 0.0, 0.0f));
	if (rot.y != 0.0f) q *= ofQuaternion(rot.y, ofVec3f(0.0f, 1.0, 0.0f));
	if (rot.z != 0.0f) q *= ofQuaternion(rot.z, ofVec3f(0.0f, 0.0, 1.0f));
	
	ofMatrix4x4 m;
	m.rotate(q);
	
	return m;

}

void ofApp::drawStructure(){
	
	for (int i = 0; i < rotations.size(); i++)
	{
		ofPushMatrix();
		ofMultMatrix(returnMatrix(rotations[i]));
		
		ofSetColor(150,150,150,50);
		if (!hideWireframe)
		{
			ofDrawCylinder(basePoint, size, height);
		}
		ofPushMatrix();
			ofRotateDeg(90, 1, 0, 0);
			//ofDrawCircle(0, 0, size);
			ofPath circle;
			circle.setCircleResolution(50);
			circle.arc(basePoint, size + 2, size + 2, 0, 360);
			circle.close();
			circle.arc(basePoint, size - 2, size - 2, 0, 360);
			circle.draw();
		
		ofPopMatrix();
		
		ofSetColor(255);
		ofDrawSphere(size, 0, 0, 5);
		size -= stepDown;
	}

	
	
}

void ofApp::popMatrices(){
	for (int i = 0; i < rotations.size(); i++)
	{
		ofPopMatrix();
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key == OF_KEY_UP)
	{
		hideWireframe = !hideWireframe;
	}
    

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
