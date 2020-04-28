
#ifndef TRAVELLER_GRAPH_GRAPHNODE_HH
#define TRAVELLER_GRAPH_GRAPHNODE_HH

#include <vector>
#include <memory>

template <typename T,typename U> class GraphVedge;
template <typename T> class GraphNode
{
public:
    GraphNode(T Elem);
    GraphVedge<T,bool> addVedge(std::shared_ptr<GraphNode<T>> Target);

private:
    T Elem;
    std::vector<GraphVedge<T,bool>> Vedges;
};

#include "GraphVedge.hh"

template <typename T> GraphNode<T>::GraphNode(T Elem): Elem(Elem) {

}

template <typename T> GraphVedge<T,bool> GraphNode<T>::addVedge(std::shared_ptr<GraphNode<T>> Target){
    GraphVedge<T,bool> Vedge(std::move(Target));
    this->Vedges.push_back(Vedge);
    return Vedge;

}

#endif //TRAVELLER_GRAPH_GRAPHNODE_HH
