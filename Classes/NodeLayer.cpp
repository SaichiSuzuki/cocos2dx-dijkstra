//
//  NodeLayer.cpp
//  Dijkstra
//
//  Created by saichi on 2016/02/21.
//
//

#include "NodeLayer.hpp"

USING_NS_CC;
using namespace std;

bool NodeLayer::init(){
    if(!Layer::init()){
        return false;
    }
//    Size winSize = Director::getInstance()->getVisibleSize();
    
    return true;
}
