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
    ofSetCircleResolution(64);
    TweenUtil.init();
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
//    update();
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
            draw_semi_circle_path(start_y,4);
            draw_semi_circle_path(start_y*0.8,2);
            break;
        default:
            break;
    }
}

//-------------------------------------------------------------------------------

void StrechyRectSwiper::set_color(ofColor color){
    this->color = color;
}

//-------------------------------------------------------------------------------

void StrechyRectSwiper::draw_semi_circle_path(float radius, int div_num){
    
    /*
     widthがarcのバームクーヘンみたいな感じの厚さ
     div_numは分割する際の線の数 eg.3
     arc_divはその分割数での180を割った値　eg.60
     arc_sizeは一つ一つの図形の角度の範囲の1/2 eg.
     */
    float width = 30;
    float arc_div = 180.0/div_num;
    float arc_size = arc_div/2.5;
    
    //緑の弧
    path.clear();
    path.setColor(color);
    for(int i=0;i<=div_num;i++){
        float innner_angle = arc_div*i-arc_size;
        float outer_angle = arc_div*i+arc_size;
        path.moveTo(ofGetWidth()/2, ofGetHeight());
        path.arc(ofGetWidth()/2, ofGetHeight(), radius, -radius, innner_angle, outer_angle);
    }
    path.draw();
    
    //黒の弧
    black_path.clear();
    black_path.setColor(0);
    for(int i=0;i<=div_num;i++){
        float innner_angle = arc_div*i-arc_size;
        float outer_angle = arc_div*i+arc_size;
        black_path.moveTo(ofGetWidth()/2, ofGetHeight());
        black_path.arc(ofGetWidth()/2, ofGetHeight(), radius-width,width-radius, innner_angle, outer_angle);
    }
    black_path.draw();
}

//-------------------------------------------------------------------------------

void StrechyRectSwiper::init_path(){
    path.setMode(ofPath::POLYLINES);
    path.setStrokeColor(color);
    path.setStrokeWidth(0);
    path.setFilled(true);
    path.setCircleResolution(60);
}


//以下Legacy的なもの

//-------------------------------------------------------------------------------
void StrechyRectSwiper::draw_semi_circular(float radius){
    //[2]外部の円
    ofSetColor(color,ofRandom(255));
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

//-------------------------------------------------------------------------------

