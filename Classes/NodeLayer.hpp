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
    int getDepth();
    int getCost();
    NodeLayer* getComeNode();
    void setDepth(int depth);
    void setKind(int kind);
    void setCost(int cost);
    void setComeNode(NodeLayer* node);
    void addNeighborNode(NodeLayer* node, int dist);
    void dataInit();
    Vector<NodeLayer*> getNeighborNode();
    std::vector<int> getNeighborNodeDist();
private:
    int id;
    /** mapの種類 */
    int kind;
    /** 隣のnode */
    Vector<NodeLayer*> neighborNodes;
    std::vector<int> neighborNodeDist;
    /** ダイクストラ用 */
    NodeLayer* comeNode;
    int cost;
    int depth;
};

#endif /* NodeLayer_hpp */
