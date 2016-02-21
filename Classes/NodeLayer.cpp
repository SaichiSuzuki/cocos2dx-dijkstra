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

NodeLayer::NodeLayer() {}

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
int NodeLayer::getId() {
    return this->id;
}
void NodeLayer::setKind(int kind) {
    if (kind == 1) {
        auto bg = LayerColor::create(Color4B(240, 220, 230, 255), getContentSize().width, getContentSize().height);
        this->addChild(bg);
    }
    else {
        auto bg = LayerColor::create(Color4B(220, 230, 240, 255), getContentSize().width, getContentSize().height);
        this->addChild(bg);
    }
}

void NodeLayer::addNeighborNode(NodeLayer* node) {
    neighborNode.pushBack(node);
}
Vector<NodeLayer*> NodeLayer::getNeighborNode() {
    return neighborNode;
}