//
//  AnimationUtility.h
//  oF_Fade_Sample
//
//  Created by HirokiNaganuma on 2015/09/16.
//
//

#ifndef __oF_Fade_Sample__AnimationUtility__
#define __oF_Fade_Sample__AnimationUtility__

#include <stdio.h>
#include "ofMain.h"

#endif /* defined(__oF_Fade_Sample__AnimationUtility__) */
class FadeBackgroundUtil{
private :
    float duration = 1000;//1000msがデフォルト
    float alpha;
    float max_closs_length;
    void update_alpha();
    float update_closs_size();
    
public:
    FadeBackgroundUtil(){};
    void set_fade_duration(float duration);
    void fade_cross_background(float x, float y, float interval);
};