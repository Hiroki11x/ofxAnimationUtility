//
//  JsonScene.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/06.
//
//

#include "JsonScene.h"

void JsonScene::init(){
    
}
void JsonScene::update(){
    JsonReceiver::recieve();
}
void JsonScene::draw(){
    for(int i = 0; i < JsonReceiver::usersInfo.size(); i++){
        float y = ((100*i)/(int)ofGetWidth())*100;
        JsonReceiver::usersInfo.at(i).icon.draw( 100 * i, y, 100, 100);
    }
}