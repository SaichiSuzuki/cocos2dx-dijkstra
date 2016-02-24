//
//  BoardLayer.hpp
//  Dijkstra
//
//  Created by saichi on 2016/02/21.
//
//

#ifndef BoardLayer_hpp
#define BoardLayer_hpp

#include <stdio.h>
#include "NodeLayer.hpp"

USING_NS_CC;

class BoardLayer : public cocos2d::Layer{
public:
    virtual bool init();
    CREATE_FUNC(BoardLayer);
    void createBoard(int x, int y);
    Vector<NodeLayer*> searchRoute(int sId, int gId);
    void breadthFirstSearch(int sId, int gId);
    Vector<NodeLayer*> setRoute(Vector<NodeLayer*>, int gId);
    Vector<NodeLayer*> getAllNode();
private:
    Size winSize;
    void createNode(int x, int y);
    void setNeighborNode(int x, int y);
    /** 全ノード */
    Vector<NodeLayer*> allNode;
};

#endif /* BoardLayer_hpp */
