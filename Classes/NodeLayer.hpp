//
//  NodeLayer.hpp
//  Dijkstra
//
//  Created by saichi on 2016/02/21.
//
//

#ifndef NodeLayer_hpp
#define NodeLayer_hpp

USING_NS_CC;

class NodeLayer : public cocos2d::Layer{
public:
    NodeLayer();
    virtual bool init();
    CREATE_FUNC(NodeLayer);
    void setId(int id);
    int getId();
    void setKind(int kind);
    void addNeighborNode(NodeLayer* node);
    Vector<NodeLayer*> getNeighborNode();
private:
    int id;
    /** mapの種類 */
    int kind;
    /** 隣のnode */
    Vector<NodeLayer*> neighborNode;
    /** ダイクストラ用 */
    int comeNode;
    int cost;
};

#endif /* NodeLayer_hpp */
