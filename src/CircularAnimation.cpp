//
//  CircularAnimation.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/26.
//
//

#include "CircularAnimation.h"


void CircularAnimation::update_duration(){
    elapsed_time+=10;
}

void CircularAnimation::update(){
    update_duration();
}

void CircularAnimation::setup(ofVec2f position){
    elapsed_time=0;
    this->position = position;
}

void CircularAnimation::draw_circular_animation(bool is_animation){
    this->is_animation = is_animation;
    if(this->is_animation){
        update();
    }
    
    if(elapsed_time>duration){
        this->is_animation = false;
    }
}//trueとなるタイミングからanimationスタート