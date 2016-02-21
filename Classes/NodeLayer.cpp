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

void NodeLayer::setId(int id) {
    this->id = id;
    log("set id:%d", id);
}
void NodeLayer::setKind(int kind) {
    auto bg = LayerColor::create(Color4B(240, 220, 230, 255), getContentSize().width, getContentSize().height);
    this->addChild(bg);
}