//
//  RectSwiper.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/04.
//
//

#include "RectSwiper.h"


void RectSwiper::init(){
    TweenUtil.init();
    TweenUtil.set_max(ofGetWidth());
    TweenUtil.set_delay(200);
    TweenUtil.set_duration(500);
}

void RectSwiper::draw(){
    TweenUtil.update();
    float start_y = TweenUtil.get_update_value();
    ofRect(0,start_y, ofGetWidth(),20);
}