
#ifndef TRAVELLER_GRAPH_GRAPHNODE_HH
#define TRAVELLER_GRAPH_GRAPHNODE_HH

#include <vector>
#include <memory>

template <typename T,typename U> class GraphVedge;
template <typename T> class GraphNode
{
public:
    GraphNode(T Elem);
    GraphVedge<T,bool> addEdge(std::shared_ptr<GraphNode<T>> Target);
    const std::vector<GraphVedge<T, bool>> &getVedges() const;
    T getElem() const;
private:
    T Elem;
    std::vector<GraphVedge<T,bool>> Vedges;

};

#include "GraphVedge.hh"

template <typename T> GraphNode<T>::GraphNode(T Elem): Elem(Elem) {

}

template <typename T> GraphVedge<T,bool> GraphNode<T>::addEdge(std::shared_ptr<GraphNode<T>> Target){
    GraphVedge<T,bool> Vedge(std::move(Target));
    this->Vedges.push_back(Vedge);
    return Vedge;
}

template<typename T> const std::vector<GraphVedge<T, bool>> &GraphNode<T>::getVedges() const {
    return Vedges;
}

template<typename T> T GraphNode<T>::getElem() const {
    return Elem;
}

#endif //TRAVELLER_GRAPH_GRAPHNODE_HH
