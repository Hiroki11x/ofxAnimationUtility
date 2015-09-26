//
//  CircularAnimation.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/26.
//
//

#ifndef __ofxAnimationUtility__CircularAnimation__
#define __ofxAnimationUtility__CircularAnimation__

#include "ofMain.h"

class CircularAnimation{
    
private:
    ofVec2f position;
    float frame_rate;
    float max_size;
    float circle_size;
    float accelerate_size;
    float duration;
    float elapsed_time;
    float is_animation;//これがtrueのときはアニメーションする
    
    float calculate_size_accelerate(float max_size, float duration);//1秒間あたりに増える円のサイズを計算
    
    void update_circle_size();
    void update_duration();
    void update();
    
public:
    CircularAnimation(){};
    void set_duration(float duration);//sで入れて欲しい
    void set_max_size(float max_size);//円の最大サイズ
    void set_frame_rate(float frame_rate);
    void setup(ofVec2f position);
    void draw_circular_animation(bool);//trueとなるタイミングからanimationスタート
    bool is_dead();
};
#endif /* defined(__ofxAnimationUtility__CircularAnimation__) */
