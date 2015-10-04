//
//  AlphaSwiper.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/04.
//
//

#include "AlphaSwiper.h"

void AlphaSwiper::init(){
    TweenUtil.set_max(100);
    TweenUtil.set_delay(100);
    TweenUtil.set_duration(ofRandom(100,200));
    TweenUtil.init();
}

void AlphaSwiper::update(){
    if(TweenUtil.get_update_value()>= 100){
        init();
    }
}

void AlphaSwiper::draw(){
    update();
    float tween = TweenUtil.get_update_value();
    float tween_end = tween*1.5;
    ofBackgroundGradient(ofColor(tween), ofColor(tween_end),  OF_GRADIENT_LINEAR);
}