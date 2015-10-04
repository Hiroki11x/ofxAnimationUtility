//
//  StrechyRectSwiper.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/04.
//
//

#include "StrechyRectSwiper.h"

//-------------------------------------------------------------------------------

void StrechyRectSwiper::set_mode(SwipeMode::Mode mode){
    this->mode = mode;
}

//-------------------------------------------------------------------------------

void StrechyRectSwiper::init(){
    init_path();
    TweenUtil.init();
    TweenUtil.set_max(ofGetWidth());
    TweenUtil.set_delay(200);
    TweenUtil.set_duration(ofRandom(200,800));
}

//-------------------------------------------------------------------------------

void StrechyRectSwiper::update(){
    if(TweenUtil.get_update_value()> ofGetHeight()){
        init();
    }
}

//-------------------------------------------------------------------------------

void StrechyRectSwiper::draw(){
    float start_y = TweenUtil.get_update_value();
    ofSetColor(color,ofRandom(255));
    
    switch (mode) {
        case SwipeMode::Down:
            ofRect(0,start_y-40, ofGetWidth(),20+start_y/5);
            break;
        case SwipeMode::Up:
            ofRect(0,ofGetHeight() - start_y, ofGetWidth(),20+start_y/5);
            return ;
        case SwipeMode::SemiCircle:
            //SemiCirculePathを用いる
            semipath[0].draw(start_y*1.3);
            semipath[1].draw(start_y);
            semipath[2].draw(start_y*0.7);
            break;
        default:
            break;
    }
}

//-------------------------------------------------------------------------------

void StrechyRectSwiper::set_color(ofColor color){
    this->color = color;
    semipath[0].set_color(color);
    semipath[1].set_color(color);
    semipath[2].set_color(color);
}

//-------------------------------------------------------------------------------

void StrechyRectSwiper::init_path(){
    semipath[0].init();
    semipath[0].set_div_num(ofRandom(2,4));
    semipath[0].set_width(ofRandom(30,100));
    semipath[0].set_rotate_mode(true);
    
    semipath[1].init();
    semipath[1].set_div_num(ofRandom(2,5));
    semipath[1].set_width(ofRandom(30,100));
    semipath[0].set_rotate_mode(false);
    
    semipath[2].init();
    semipath[2].set_div_num(ofRandom(2,5));
    semipath[2].set_width(ofRandom(30,100));
    semipath[0].set_rotate_mode(true);
}


//以下Legacy的なもの
/*

//-------------------------------------------------------------------------------
void StrechyRectSwiper::draw_semi_circular(float radius){
    //[2]外部の円
    
//    ofSetColor(color,ofRandom(255));
    ofCircle(ofGetWidth()/2, ofGetHeight(), radius*1.5);
    ofSetColor(0);
    ofCircle(ofGetWidth()/2, ofGetHeight(), radius*1.3);
    
    //円をぶった切る黒いやつ
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight());
    
    for(int i=1;i<=5;i++){
        float innner_angle = 36.0*i-5.0;
        float outer_angle = 36.0*i+5.0;
        
        ofBeginShape();
        ofVertex(0, 0);
        ofVertex(2000*cos(innner_angle/180.0*PI), -2000*sin(innner_angle/180.0*PI));
        ofVertex(2000*cos(outer_angle/180.0*PI), -2000*sin(outer_angle/180.0*PI));
        ofEndShape();
    }
    ofPopMatrix();
    
    //[1]内部の円
    ofCircle(ofGetWidth()/2, ofGetHeight(), radius*1.1);
    ofSetColor(0);
    ofCircle(ofGetWidth()/2, ofGetHeight(), radius*0.9);
    
    //円をぶった切る黒いやつ
    ofPushMatrix();
    ofBeginShape();
    ofTranslate(ofGetWidth()/2, ofGetHeight());
    ofVertex(0, 0);
    ofVertex(2000*cos(60.0/180.0*PI), -2000*sin(60.0/180.0*PI));
    ofVertex(2000*cos(120.0/180.0*PI), -2000*sin(120.0/180.0*PI));
    ofEndShape();
    ofPopMatrix();
}
*/
//-------------------------------------------------------------------------------

