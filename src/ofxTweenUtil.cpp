//
//  ofxTweenUtil.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/03.
//
//

#include "ofxTweenUtil.h"

void ofxTweenUtil::setup(){
    init();
}

void ofxTweenUtil::set_duration(unsigned int duration){
    this->duration = duration;
}

void ofxTweenUtil::set_delay(unsigned int delay){
    this->delay = delay;
}

void ofxTweenUtil::update(){
//    if(tweenlinear.update() > ofGetHeight()){
//        init();
//    }
}

float ofxTweenUtil::get_update_value(){
    return tweenlinear.update();
}

void ofxTweenUtil::draw(){//test用の関数、実際は使わない
//    cout<< tweencubic.update() << ""<<endl;
//    ofDrawBitmapString(ofToString(tweencubic.update()), 100,120);
//    ofRect(20,140,tweencubic.update(),20);
    
    ofDrawBitmapString(ofToString(tweenlinear.update()), 300,120);
    ofRect(20,180,tweenlinear.update(),20);
}

void ofxTweenUtil::init(){
    //ofxTween#setParameters(int id, ofxEasing &easing, ofxTween::ofxEasingType type, float from, float to, unsigned int duration, unsigned int delay)
    
//    int id_1 =1;
//    tweencubic.setParameters(id_1,easingcubic,ofxTween::easeOut,0,ofGetWidth(),duration,delay);
    
    int id_2 =2;
    tweenlinear.setParameters(id_2,elasticlinnear,ofxTween::easeInOut,0 , ofGetWidth(), duration, delay);
}