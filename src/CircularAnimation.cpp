//
//  CircularAnimation.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/26.
//
//

#include "CircularAnimation.h"


void CircularAnimation::set_duration(float duration){
    this->duration = duration;
}//sで入れて欲しい

void CircularAnimation::set_max_size(float max_size){
    this->max_size = max_size;
}//円の最大サイズ

void CircularAnimation::update_duration(){
    elapsed_time += (1.0f/frame_rate);//1秒間に1増加する
}

float CircularAnimation::calculate_size_accelerate(float max_size, float duration){//1回の更新でどれだけcircle_sizeを増加させればいいか計算
    float result = (max_size/duration);//1秒間に増加すべき値はこれ
    return result/frame_rate;
}

void CircularAnimation::update_circle_size(){
    circle_size += accelerate_size;
}

void CircularAnimation::update(){
    update_duration();
    update_circle_size();
}

void CircularAnimation::set_frame_rate(float frame_rate){
    this->frame_rate = frame_rate;
}

void CircularAnimation::setup(ofVec2f position){
    elapsed_time=0.0f;
    circle_size=0.0f;
    this->position = position;
    accelerate_size = calculate_size_accelerate(max_size,duration);
}

void CircularAnimation::draw_circular_animation(bool is_animation){
    if(elapsed_time>duration){
        this->is_animation = false;
    }else{
        this->is_animation = is_animation;
        if(this->is_animation){
            update();
            ofFill();
            ofSetColor(100, ofRandom(100));
            ofCircle(position, circle_size);
        }
    }
}//trueとなるタイミングからanimationスタート

bool CircularAnimation::is_dead(){
    return is_animation;
}
