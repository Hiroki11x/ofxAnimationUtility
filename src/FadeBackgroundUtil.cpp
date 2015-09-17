//
//  AnimationUtility.cpp
//  oF_Fade_Sample
//
//  Created by HirokiNaganuma on 2015/09/16.
//
//

#include "FadeBackgroundUtil.h"

void FadeBackgroundUtil::fade_cross_background(float x, float y, float interval){
    float pos_x,pos_y;
    max_closs_length = interval/8;
    float margin = 30;
    ofTranslate(x, y);
    ofBackground(0);
    update_alpha();
    float closs_length = update_closs_size();
    ofSetColor(255,alpha);
    int x_num = ofGetWidth()/interval;
    int y_num = ofGetHeight()/interval;
    for(int i = 0 ; i<=x_num ; i++ ){
        for(int j = 0 ; j<=y_num ; j++ ){
            pos_x = interval*i +margin;
            pos_y = interval*j +margin;
            ofLine(pos_x-closs_length, pos_y, pos_x+closs_length, pos_y);
            ofLine(pos_x, pos_y-closs_length, pos_x, pos_y+closs_length);
        }
    }
    ofTranslate(-x, -y);
}

void FadeBackgroundUtil::set_fade_duration(float duration){
    this->duration = duration;
}

void FadeBackgroundUtil::update_alpha(){//透明度を変えていくやつ
    alpha = 255 * pow(sin(PI*ofGetElapsedTimeMillis()/duration),2);
}

float FadeBackgroundUtil::update_closs_size(){
    return max_closs_length * pow(sin(PI*ofGetElapsedTimeMillis()/duration),2);
}


