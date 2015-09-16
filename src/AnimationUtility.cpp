//
//  AnimationUtility.cpp
//  oF_Fade_Sample
//
//  Created by HirokiNaganuma on 2015/09/16.
//
//

#include "AnimationUtility.h"

void AnimationUtility::fade_background(float x, float y, float interval){
    float pos_x,pos_y;
    float length = interval/8;
    float margin = 30;
    ofTranslate(x, y);
    ofBackground(0);
    update_alpha();
    ofSetColor(255,alpha);
    int x_num = ofGetWidth()/interval;
    int y_num = ofGetHeight()/interval;
    for(int i = 0 ; i<=x_num ; i++ ){
        for(int j = 0 ; j<=y_num ; j++ ){
            pos_x = interval*i +margin;
            pos_y = interval*j +margin;
            ofLine(pos_x-length, pos_y, pos_x+length, pos_y);
            ofLine(pos_x, pos_y-length, pos_x, pos_y+length);
        }
    }
    ofTranslate(-x, -y);
}

void AnimationUtility::set_fade_duration(float duration){
    this->duration = duration;
}

void AnimationUtility::update_alpha(){
    alpha = 255 * pow(sin(PI*ofGetElapsedTimeMillis()/duration),2);
}