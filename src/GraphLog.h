//
//  GraphLog.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/05.
//
//

#ifndef __ofxAnimationUtility__GraphLog__
#define __ofxAnimationUtility__GraphLog__

#include "ofMain.h"

class GraphLog{
    
private:
    
    vector <float> valHistory;
    
    float max_value;
    float height_limit;
    bool isGetValue;
    
public:
    void setup();
    void update(float arg);
    void draw();
    void set_height_limit(float arg);
    
    void keyPressed(int key);
};
#endif /* defined(__ofxAnimationUtility__GraphLog__) */
