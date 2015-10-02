//
//  FadeMotionGraphics.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/02.
//
//  円を中心として長方形や文字列が回ったりするアニメーション
//

#include "FadeMotionGraphics.h"



void FadeMotionGraphics::draw(){
    ofPushMatrix();
    for(int i =0 ;i<rect_swiper.size(); i++){
        rect_swiper.at(i).draw();
    }
    ofPopMatrix();
}

void FadeMotionGraphics::update(){

}

void FadeMotionGraphics::init(){
    for(int i=0;i<30;i++){
        rect_swiper.push_back(RectSwiper());
        rect_swiper.back().set_angle(i*120);
        rect_swiper.back().init();
    }
    
}