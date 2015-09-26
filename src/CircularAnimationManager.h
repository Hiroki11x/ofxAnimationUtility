//
//  CircularAnimationManager.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/26.
//
//

#ifndef __ofxAnimationUtility__CircularAnimationManager__
#define __ofxAnimationUtility__CircularAnimationManager__

#include "ofMain.h"
#include "CircularAnimation.h"

class CircularAnimationManager{
private:
    vector<CircularAnimation> circularannimations;
    int animation_num;
    
    template<typename T>
    void remove(std::vector<T>& vector, unsigned int index);
    void generate_circular_animation();
    void update();
public:
    void set_animation_num(int num);
    void setup();
    void draw_animation();
};

#endif /* defined(__ofxAnimationUtility__CircularAnimationManager__) */
