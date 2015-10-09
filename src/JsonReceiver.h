//
//  JsonReceiver.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/06.
//
//

#ifndef __ofxAnimationUtility__JsonReceiver__
#define __ofxAnimationUtility__JsonReceiver__

#include "ofxJSON.h"
#include "ofMain.h"
#include "ofxSuperLogUtil.h"

class JsonReceiver {
    
public:
    struct UserInfo{//Usernameと画像情報を持つ構造体
        string userName;
        ofImage icon;
    };
    
    static string cachedTweetId;
    
    static ofxJSONElement jsonElement;
    static vector<UserInfo> usersInfo;
    
    static void recieve(){
        
//        bool parsingSuccessful = jsonElement.openLocal("MAU_twit/twitter.json");//Nodeで取得したJSON
        //Nodeを　プロジェクトディレクトリとおなじ階層にいれた
        
        bool parsingSuccessful = jsonElement.openLocal("../../../MAU_twit/twitter.json");//Nodeで取得したJSON

//        parsingSuccessful =false; // Node動かさないときはこのコメントを外す
        
        static ofxSuperLogUtil log;
        
        if (parsingSuccessful){
            if(checkUpdateJson()){//新規キャッシュの際はパース
                log.set_log(parseJson());
            }
        }else{
            cout << "Failed to parse JSON" << endl;
        }
    };
    static string parseJson(){//userInfonい貯めていく
        ofImage img;
        img.loadImage(jsonElement["user"]["profile_image_url"].asCString());
        if(img.getWidth() == 0){return;}
        usersInfo.push_back((UserInfo){jsonElement["user"]["name"].asCString(),img});
        return ofToString(jsonElement);
    };
    static bool checkUpdateJson(){
        if(jsonElement["id_str"].asCString() != cachedTweetId){//JSONで読んだidがキャッシュされていなかったらキャッシュ
            cachedTweetId = jsonElement["id_str"].asCString();
            return true;
        }else{
            return false;
        }
    };
    
private:
    JsonReceiver(){};
};

#endif /* defined(__ofxAnimationUtility__JsonReceiver__) */
