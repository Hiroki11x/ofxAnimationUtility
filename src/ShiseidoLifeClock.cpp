//
//  ShiseidoLifeClock.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/12.
//
//

#include "ShiseidoLifeClock.h"

void ShiseidoLifeClock::init(){
    for(int i = 0;i< 300 ;i++){
        vec.push_back(ofVec2f());
        vec.back() = ofVec2f(
                             cos(ofSignedNoise(ofGetFrameNum()/1000.0,i,i)*2*PI),
                             sin(ofSignedNoise(ofGetFrameNum()/1000.0,i,i)*2*PI)
                             );
        vec.back() *= 2 00;
    }
}

void ShiseidoLifeClock::draw(){
    
    switch (mode) {
        case 0:
            draw_default_circle();
            break;
        case 1:
            draw_bezier_map();
            break;
        default:
            break;
    }
}

void ShiseidoLifeClock::update(){
    for(int i = 0;i< vec.size() ;i++){
        vec.at(i) = ofVec2f(
                            cos(ofSignedNoise(ofGetFrameNum()/3000.0,i)*2*PI),
                            sin(ofSignedNoise(ofGetFrameNum()/3000.0,i)*2*PI)
                            );
        vec.at(i)*= 400;
    }
}

void ShiseidoLifeClock::draw_bezier_map(){
    
    update();
    
    ofNoFill();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    
    int index1,index2,index3;
    for(int i = 0;i<vec.size();i++){
        
        ofSetColor(ofColor::fromHsb((ofMap(i, 0, vec.size(), 0, 255)), 200, 200));
        
        index1 = pow(ofSignedNoise(i,ofGetFrameNum()/1000),2)*vec.size();
        index3 = pow(ofSignedNoise(i,ofGetElapsedTimef()/100),2)*vec.size();
        ofBezier(vec.at(index1).x,vec.at(index1).y,
                 vec.at(index1).x/4,vec.at(index1).y/4,
                 vec.at(index3).x/4,vec.at(index3).y/4,
                 vec.at(index3).x,vec.at(index3).y);
        
        ofCircle(vec.at(index3)*1.01,2);
    }
    
    ofPopMatrix();
}


void ShiseidoLifeClock::draw_default_circle(){
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

