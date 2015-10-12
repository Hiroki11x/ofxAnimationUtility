//
//  ShiseidoLifeClock.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/12.
//
//

#include "ShiseidoLifeClock.h"

void ShiseidoLifeClock::draw(){
    ofVec2f basis_vec;//大きい全体のベクトル
    ofVec2f inner_vec;//Bezier用の中間点ベクトル
    int angle;
    int hue;
    
    ofSetLineWidth(0.1);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    
    for(int i =0;i<ofGetElapsedTimef()*10;i+=1){
        angle = i;
        inner_vec = ofVec2f(
                            cos(ofSignedNoise(ofGetFrameNum()/1000.0,i,i)*2*PI),
                            sin(ofSignedNoise(ofGetFrameNum()/1000.0,i,i)*2*PI)
                            );
        inner_vec *= 50;
        
        basis_vec = ofVec2f(
                            cos(angle/180.0*PI),
                            sin(angle/180.0*PI)
                            );
        basis_vec *= 300;
        
        hue = ofMap(i, 0, 360, 0, 255);
        
        ofSetColor(ofColor::fromHsb(hue, 170, 200));
        ofNoFill();
        ofBezier(0, 0,
                 basis_vec.x/2+inner_vec.x,basis_vec.y/2+inner_vec.y,
                 basis_vec.x+inner_vec.x, basis_vec.y+inner_vec.y,
                 basis_vec.x, basis_vec.y);
        ofFill();
        ofCircle(basis_vec.x*1.01, basis_vec.y*1.01, 1);
    }
    ofPopMatrix();
}