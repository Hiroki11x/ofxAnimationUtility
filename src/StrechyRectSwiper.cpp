//
//  StrechyRectSwiper.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/04.
//
//

#include "StrechyRectSwiper.h"

void StrechyRectSwiper::set_mode(SwipeMode::Mode mode){
    this->mode = mode;
}

void StrechyRectSwiper::init(){
    TweenUtil.init();
    TweenUtil.set_delay(200);
    TweenUtil.set_duration(500);
}

void StrechyRectSwiper::draw(){
    
    TweenUtil.update();
    float start_y = TweenUtil.get_update_value();
    ofSetColor(color,ofRandom(255));
    
    switch (mode) {
        case SwipeMode::Down:
            ofRect(0,start_y, ofGetWidth(),20+start_y/5);
            break;
        case SwipeMode::Up:
            float endLine = ofGetHeight();
            ofRect(0,endLine - start_y, ofGetWidth(),20+start_y/5);
            break;
    }
}

void StrechyRectSwiper::set_color(ofColor color){
    this->color = color;
}