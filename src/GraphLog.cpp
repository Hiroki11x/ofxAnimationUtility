//
//  GraphLog.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/05.
//
//

#include "GraphLog.h"

void GraphLog::setup(){
    valHistory.assign(400, 0.0);
    max_value=0.0f;
    isGetValue= false;
}

void GraphLog::set_height_limit(float arg){
    height_limit = arg;
}


void GraphLog::update(float arg){
    
    //0-1の何かしらの値を入れる
    valHistory.push_back(arg);
    
    //valHistoryの登録数に制限を設けてそれ以上になるとレコードを削除
    if( valHistory.size() >= 400 ){
        valHistory.erase(valHistory.begin(), valHistory.begin()+1);
    }
}


void GraphLog::draw(){
    //----------------------------lets draw the volume history as a graph----------------------------
    
    if(isGetValue){
        ofPushStyle();
        ofNoFill();
        float extend = (float)ofGetWidth()/(valHistory.size()-1);//ここを大きくすればするほど間隔が大きくなる
        
        ofSetColor(0,200,0,100);//ログの線の色
        ofBeginShape();
        for (unsigned int i = 0; i < valHistory.size(); i++){
            if( i == 0 ){//左端の点
                ofVertex(i*extend, ofGetHeight());
            }else if( i == valHistory.size()-1 ) {//右端の点
                ofVertex(i*extend, ofGetHeight());
            }else{
                if((i%120 && valHistory[i]>valHistory[i-1] && valHistory[i]>valHistory[i+1])|| (i%120 &&valHistory[i]==1 && valHistory[i+1]==1)){//valueが最大もしくは極大値である時数値をだす
                    ofDrawBitmapString(ofToString(valHistory[i] * height_limit), i*extend,  ofGetHeight()- valHistory[i] * height_limit);
                }
                ofVertex(i*extend,  ofGetHeight()- valHistory[i] * height_limit);
            }
            
            if(max_value <valHistory[i]*height_limit && isGetValue){//volの最大値が更新されたら、かつ、入力状態にある時
                max_value=valHistory[i]*height_limit;
            }
            
        }
        ofEndShape(false);
        ofPopStyle();
    }else{
        max_value=0;
//        valHistory[i]=0;//valueの履歴を消去
    }

}

void GraphLog::keyPressed(int key){
    if(key==OF_KEY_UP){
        max_value=0;
        isGetValue= true;
    }
    if(key==OF_KEY_DOWN){
        isGetValue= false;
        valHistory.erase(valHistory.begin(), valHistory.begin()+1);
    }
}