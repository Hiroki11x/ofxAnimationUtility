#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(5);
    animation.set_fade_duration(2000);
    delaunay.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    delaunay.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    animation.fade_cross_background(0, 0, 100);
    delaunay.draw();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(int i = 0;i<10;i++){
        delaunay.generate(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
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
    delaunay.generate(x,y);

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
