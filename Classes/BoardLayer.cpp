//
//  BoardLayer.cpp
//  Dijkstra
//
//  Created by saichi on 2016/02/21.
//
//

#include "BoardLayer.hpp"
#include "NodeLayer.hpp"

USING_NS_CC;
using namespace std;

bool BoardLayer::init(){
    if(!Layer::init()){
        return false;
    }
    winSize = Director::getInstance()->getVisibleSize();
    return true;
}

void BoardLayer::createBoard(int x, int y){
    // ボード(背景)作成
    auto bg = LayerColor::create(Color4B::BLACK, winSize.width, winSize.width);
    this->addChild(bg);
    // ノード(マス)作成
    createNode(x, y);
}
void BoardLayer::createNode(int x, int y){
    log("%d * %d マスで生成します", x, y);
    int id = 0;
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            auto nl = NodeLayer::create();
            nl->setId(id);
            nl->setContentSize(Size((winSize.width/x)-3,(winSize.width/x)-3));
            nl->setKind(1);
//            nl->setPosition(Vec2((winSize.width/10)*i-(winSize.width/20), (winSize.width/10)*j-(winSize.width/20)));
            nl->setPosition(Vec2((winSize.width/x)*i, (winSize.width/x)*j));
            this->addChild(nl);
            allNode.pushBack(nl);
            id ++;
        }
    }
}