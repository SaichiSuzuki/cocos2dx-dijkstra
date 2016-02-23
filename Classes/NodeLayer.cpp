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

int NodeLayer::getId() {
    return this->id;
}
void NodeLayer::setId(int id) {
    this->id = id;
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
void NodeLayer::setDepth(int depth) {
    this->depth = depth;
}
void NodeLayer::setCost(int cost) {
    this->cost = cost;
}
void NodeLayer::setComeNode(NodeLayer* node) {
    this->comeNode = node;
}
/**
 *  隣ノード追加
 *  @param node ノード
 *  @param dist 距離
 */
void NodeLayer::addNeighborNode(NodeLayer* node, int dist) {
    neighborNodes.pushBack(node);
    neighborNodeDist.push_back(dist);
}
Vector<NodeLayer*> NodeLayer::getNeighborNode() {
    return neighborNodes;
}
std::vector<int> NodeLayer::getNeighborNodeDist() {
    return neighborNodeDist;
}
int NodeLayer::getDepth() {
    return depth;
}
int NodeLayer::getCost() {
    return cost;
}
NodeLayer* NodeLayer::getComeNode() {
    return comeNode;
}
void NodeLayer::dataInit() {
    comeNode = NULL;
    cost = 1000;
    depth = -1;
}