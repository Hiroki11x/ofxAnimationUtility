//
//  TerminalScene.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/11.
//
//

#ifndef __ofxAnimationUtility__TerminalScene__
#define __ofxAnimationUtility__TerminalScene__

#include "ofMain.h"
#include "StringElement.h"

class TerminalScene{
public:
    void init();
    void update();
    void draw();
private:
    string argString;
    StringElement stringElement;
};

#endif /* defined(__ofxAnimationUtility__TerminalScene__) */
