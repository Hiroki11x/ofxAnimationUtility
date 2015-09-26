#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofToggleFullscreen();
    ofBackground(0);
    ofSetFrameRate(5);
    
    animation.set_fade_duration(2000);
    
    delaunay.setup();
    
    ofColor color;
    color.set(0, 255, 0);
    pathmanager.set_path_color(color);
    pathmanager.setup_path(100);
    
    linebelt.setup_belt(1000);

    circularannimationmanager.set_animation_num(200);
    circularannimationmanager.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    //delaunay.update();
    pathmanager.update_path();
    linebelt.update_belt();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    animation.fade_cross_background(0, 0, 100);
//    delaunay.draw();
    //pathmanager.draw_path();
    linebelt.draw_belt();
    circularannimationmanager.draw_animation();
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f'){
        ofToggleFullscreen();
    }else if(key =='s'){
        linebelt.set_mode();
    }else{
        for(int i = 0;i<1;i++){
            delaunay.generate(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        }
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
