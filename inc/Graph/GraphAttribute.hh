//
// Created by norbert on 24.04.20.
//

#ifndef TRAVELLER_GRAPH_GRAPHATTRIBUTE_HH
#define TRAVELLER_GRAPH_GRAPHATTRIBUTE_HH

#include <memory>


template <typename T> class GraphNode;
template <typename ATTR,typename  T> class GraphAttribute {
private:
    ATTR attribute;
    std::shared_ptr<GraphNode<T>> Node;
public:
    GraphAttribute(ATTR attribute,decltype(Node) Node);


};

#include "GraphNode.hh"

template <typename ATTR,typename T> GraphAttribute<ATTR,T>::GraphAttribute(ATTR attribute,decltype(Node) Node){
    this->attribute = attribute;
    this->Node = Node;
}


#endif //TRAVELLER_GRAPH_GRAPHATTRIBUTE_HH
