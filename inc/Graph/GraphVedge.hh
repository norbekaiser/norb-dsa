
#ifndef TRAVELLER_GRAPH_GRAPHVEDGE_HH
#define TRAVELLER_GRAPH_GRAPHVEDGE_HH

#include <memory>

template <typename T> class GraphNode;
template <typename T,typename U> class GraphVedge {
public:
    GraphVedge(std::shared_ptr<GraphNode<T>> Target);
    const std::shared_ptr<GraphNode<T>> &getTarget() const;
    U getWeight() const;
private:
    std::shared_ptr<GraphNode<T>> Target;
    U weight;
};

#include "GraphNode.hh"

template <typename T,typename U> GraphVedge<T,U>::GraphVedge(std::shared_ptr<GraphNode<T>> Target): Target(std::move(Target)){

}

template<typename T, typename U> const std::shared_ptr<GraphNode<T>> &GraphVedge<T, U>::getTarget() const {
    return Target;
}

template<typename T, typename U> U GraphVedge<T, U>::getWeight() const {
    return weight;
}

#endif //TRAVELLER_GRAPH_GRAPHVEDGE_HH
