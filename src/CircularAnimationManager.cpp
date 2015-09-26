//
//  CircularAnimationManager.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/26.
//
//

#include "CircularAnimationManager.h"

// vectorからindex番目の要素を削除する
template<typename T>
void CircularAnimationManager::remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

void CircularAnimationManager::setup(){
    generate_circular_animation();
}

void CircularAnimationManager::generate_circular_animation(){
    for(int i = 0; i<animation_num;i++){
        circularannimations.push_back(CircularAnimation());
        circularannimations.back().set_frame_rate(5);
        circularannimations.back().set_duration(ofRandom(10,30));
        circularannimations.back().set_max_size(ofRandom(30,900));
        circularannimations.back().setup(ofVec2f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())));
    }
}

void CircularAnimationManager::set_animation_num(int num){
    this->animation_num = num;
}

void CircularAnimationManager::draw_animation(){
    for(int i = 0; i<circularannimations.size();i++){
        circularannimations.at(i).draw_circular_animation(true);
    }
//    update();//TODO
}

void CircularAnimationManager::update(){
    for(int i = 0; i<circularannimations.size();i++){
        if(circularannimations.at(i).is_dead()){
            remove(circularannimations, i);
        }
    }
}



