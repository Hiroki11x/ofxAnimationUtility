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
class AnimationUtility{
private :
    float duration = 1000;//1000msがデフォルト
    float alpha;
    void update_alpha();
    
public:
    AnimationUtility(){};
    void set_fade_duration(float duration);
    void fade_background(float x, float y, float interval);
};