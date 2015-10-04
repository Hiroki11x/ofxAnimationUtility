#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofToggleFullscreen();
    ofBackground(0);
    ofSetFrameRate(60);
    mode=0;
    
    //1
    animation.set_fade_duration(2000);
    
    //2
    delaunay.setup();

    //3
    pathmanager.set_path_color(ofColor::fromHsb(ofRandom(255), 255, 255));
    pathmanager.setup_path(100);
    
    //4
    linebelt.setup_belt(1000);

    //5
    circularannimationmanager.set_animation_num(200);
    circularannimationmanager.setup();
    
    //6
    circularvertexes.setup();
    
    //7
    fademotiongraphics.init();
    
    //8
    rectswiper.init();
    
    //9
    strechyrectswiper.init();
    strechyrectswiper.set_color(ofColor::fromHsb(100, 200, 200));
    strechyrectswiper.set_mode(SwipeMode::Up);

}

//--------------------------------------------------------------
void ofApp::update(){
    switch (mode) {
        case 2:
            //2
            delaunay.update();
            break;
        case 3:
            //3
            pathmanager.update_path();
            break;
        case 4:
            //4
            linebelt.update_belt();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(100);
    switch (mode) {
        case 1:
            //1
            animation.fade_cross_background(0, 0, 100);
            ofDrawBitmapString("[1]CrossAnimation", 20,20);
            break;
        case 2:
            //2
            delaunay.draw();
            ofDrawBitmapString("[2]Delaunay", 20,20);
            break;
        case 3:
            //3
            pathmanager.draw_path();
            ofDrawBitmapString("[3]PathManager", 20,20);
            break;
        case 4:
            //4
            linebelt.draw_belt();
            ofDrawBitmapString("[4]LineBelt", 20,20);
            break;
        case 5:
            //5
            circularannimationmanager.draw_animation();
            ofDrawBitmapString("[5]CircularRipple", 20,20);
            break;
        case 6:
            //6
            circularvertexes.draw();
            ofDrawBitmapString("[6]CircularVertexes", 20,20);
            break;
        case 7:
            //7
            fademotiongraphics.draw();
            ofDrawBitmapString("[7]FadeMotionGraphics", 20,20);
            break;
            
        case 8:
            //8
            rectswiper.draw();
            ofDrawBitmapString("[8]RectSwiper", 20,20);
            break;
            
        case 9:
            //9
            strechyrectswiper.draw();
            ofDrawBitmapString("[9]StrechyRectSwiper", 20,20);
            break;

        default:
            break;
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout<<key<<endl;
    if(key == 'f'){
        ofToggleFullscreen();
    }else if(key =='s'){
        linebelt.set_mode();
    }else if(49<=key && key<=57){
        mode = key-48;
    }else if(key==' '){
        fademotiongraphics.init();
    }else if(key==OF_KEY_DOWN){
        strechyrectswiper.set_mode(SwipeMode::Down);
        strechyrectswiper.init();
    }else if(key==OF_KEY_UP){
        strechyrectswiper.set_mode(SwipeMode::Up);
        strechyrectswiper.init();
    }
    else if(key==OF_KEY_RIGHT){
        strechyrectswiper.set_mode(SwipeMode::SemiCircle);
        strechyrectswiper.init();
    }else{
        for(int i = 0;i<1;i++){
            delaunay.generate(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    switch (mode) {
        case 2:
            delaunay.generate(x,y);
            break;
        case 8:
            rectswiper.init();
            break;
        default:
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
