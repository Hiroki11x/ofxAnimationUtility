
//
//  JsonReceiver.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/06.
//
//

#include "JsonReceiver.h"

string JsonReceiver::cachedTweetId;
ofxJSONElement JsonReceiver::jsonElement;
vector<JsonReceiver::UserInfo> JsonReceiver::usersInfo;