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

USING_NS_CC;

class BoardLayer : public cocos2d::Layer{
public:
    virtual bool init();
    CREATE_FUNC(BoardLayer);
    
    void createBoard(int x, int y);
private:
    Size winSize;
    void createNode(int x, int y);
};

#endif /* BoardLayer_hpp */
