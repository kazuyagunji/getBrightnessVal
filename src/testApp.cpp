#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetCircleResolution(360);
    
    lightSwitch = false;
    brightness = 0;
    j = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    if (lightSwitch == true) {
        brightness = Pos[j];
        j++;
        if (j > Pos.size()) {
            j = 0;
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushStyle();
    ofSetColor(255, 255, 255);
    string messageA = "canvas, drawing here!!";
    ofDrawBitmapString(messageA, 18, 340);
    string messageB = "TestBrightness";
    ofDrawBitmapString(messageB, ofGetWidth()/5 - 3, 480);
    string messageC = "ResultBrughtness";
    ofDrawBitmapString(messageC, ofGetWidth()/5 * 3 + 91, 480);
    string messageD = "keyPressed [s] = save, [r] = result, [d] = alldelete, [f] = fullscreen";
    ofDrawBitmapString(messageD, ofGetWidth() - 565, 90);
    ofPopStyle();
    
    myParticleDraw.draw();
    
    for (int i = 0; i < Pos.size(); i++) {
        ofSetColor(0, Pos[i], 0);
        ofCircle(ofGetWidth()/4, 610, 100);
    }
    
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(3);
    ofSetColor(0, 180, 180);
    ofRect(0, 100, ofGetWidth(), 256);
    ofSetColor(150, 150, 150);
    ofCircle(ofGetWidth()/4, 610, 101);
    ofCircle(ofGetWidth()/4 * 3, 610, 101);
    ofPopStyle();
    
    ofSetColor(brightness, 0, 0);
    ofCircle(ofGetWidth()/4 * 3, 610, 100);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    myParticleDraw.keyPressed(key);
    
    string msg = "(y)    ";
    if (key == 's') {
        ofFile file("brightnessVal.txt", ofFile::WriteOnly);
        for (int i = 0; i < Pos.size(); i++) {
            file<<Pos[i];
            file<<msg;
        }
    }
    
    if (key == 'r') {
        lightSwitch = true;
    }
    if (key == 'd') {
        lightSwitch = false;
        Pos.clear();
        brightness = 0;
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if (y <= 355 && y >= 99) {
        myParticleDraw.mouseDragged(x, y);
    }
    
    valY = -y + 356;
    if (valY >= 1 && valY <= 254) {
        Pos.push_back(valY);
    }
    if (y > 356) {
        Pos.push_back(0);
        myParticleDraw.mouseDragged(x, 356);
    }
    if (y < 100) {
        Pos.push_back(255);
        myParticleDraw.mouseDragged(x, 100);
    }
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}