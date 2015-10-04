//
//  SemiCirclePath.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/04.
//
//

#include "SemiCirclePath.h"

void SemiCirclePath::set_rotate_mode(bool mode){
    this->mode = mode;
}

void SemiCirclePath::set_color(ofColor color){
    this->color = color;
}

void SemiCirclePath::init(){
    green_path.setMode(ofPath::POLYLINES);
    green_path.setStrokeColor(color);
    green_path.setStrokeWidth(0);
    green_path.setFilled(true);
    green_path.setCircleResolution(60);
    black_path.setCircleResolution(64);
}

void SemiCirclePath::set_div_num(int div_num){
    this->div_num = div_num;
}


void SemiCirclePath::draw(float radius){
    
    float arc_div = 180.0/div_num;
    if(mode)arc_div+=ofGetElapsedTimef();//回転モードの際
    
    float arc_size = arc_div/2.5;
    
    //緑の弧
    green_path.clear();
    color.setBrightness(100);
    green_path.setColor(color);
    for(int i=0;i<=div_num;i++){
        float innner_angle = arc_div*i-arc_size;
        float outer_angle = arc_div*i+arc_size;
        green_path.moveTo(ofGetWidth()/2, ofGetHeight());
        green_path.arc(ofGetWidth()/2, ofGetHeight(), radius, -radius, innner_angle, outer_angle);
    }
    green_path.draw();
    
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


void SemiCirclePath::set_width(float width){
    this->width = width;
}

/*
 widthがarcのバームクーヘンみたいな感じの厚さ
 div_numは分割する際の線の数 eg.3
 arc_divはその分割数での180を割った値　eg.60
 arc_sizeは一つ一つの図形の角度の範囲の1/2 eg.
 */
