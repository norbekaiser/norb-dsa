
#ifndef TRAVELLER_GRAPH_GRAPHNODE_HH
#define TRAVELLER_GRAPH_GRAPHNODE_HH

#include <vector>

template <typename T> class GraphVedge;
template <typename T> class GraphNode
{
private:
    T Elem;
    std::vector<GraphVedge<T>> Vedges;
public:
    GraphNode(decltype(Elem) Elem);

};

#include "GraphVedge.hh"

template <typename T> GraphNode<T>::GraphNode(decltype(Elem) Elem) {
    this->Elem = Elem;
}

#endif //TRAVELLER_GRAPH_GRAPHNODE_HH
