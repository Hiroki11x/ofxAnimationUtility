//
//  TriangleElement.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/05.
//
//

#include "TriangleElement.h"

bool TriangleElement::is_fade(){
    return isfade;
}

void TriangleElement::set_color(ofColor arg_color){
    color = arg_color;
}

ofVec2f* TriangleElement::get_position(){
    return &position;
}

void TriangleElement::set_size(float size){
    this->size =size;
}

void TriangleElement::set_speed(ofVec2f speed){
    this->speed = speed;
}

void TriangleElement::set_position(ofVec2f position){
    this->position = position;
}


void TriangleElement::init(){
    
}

void TriangleElement::update(){
    if(position.x<ofGetWidth()+OFFSET && position.x> -OFFSET){
        position.x += speed.x;
    }else{
        isfade =true;
    }
    if(position.y<ofGetHeight()+OFFSET && position.y> -OFFSET){
        position.y += speed.y;
    }else{
        isfade =true;
    }
}

void TriangleElement::draw(){
    //以下をTriangle書くときにまとめて呼ぶ
//    ofPushStyle()
//    ofSetCircleResolution(60);
    update();
    
    ofPushMatrix();
    ofTranslate(position);
//    ofRotate(angle+ofGetElapsedTimef());
    ofSetColor(color,255);
    ofCircle(0,0,size);
    ofSetColor(color, ofRandom(255));
    ofCircle(0,0,size*2);
    ofSetColor(color, ofRandom(155));
    ofCircle(0,0,size*4);
    ofPopMatrix();
}