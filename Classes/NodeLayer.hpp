//
//  NodeLayer.hpp
//  Dijkstra
//
//  Created by saichi on 2016/02/21.
//
//

#ifndef NodeLayer_hpp
#define NodeLayer_hpp

#include <stdio.h>

USING_NS_CC;

class NodeLayer : public cocos2d::Layer{
public:
    virtual bool init();
    CREATE_FUNC(NodeLayer);
private:
    int id;
    /** mapの種類 */
    int kind;
    /** 隣のnode */
    Vector<int> neighborNode;
    /** ダイクストラ用 */
    int comeNode;
    int cost;
};

#endif /* NodeLayer_hpp */
