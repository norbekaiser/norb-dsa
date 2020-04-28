
#ifndef TRAVELLER_GRAPH_GRAPHVEDGE_HH
#define TRAVELLER_GRAPH_GRAPHVEDGE_HH

#include <memory>

template <typename T> class GraphNode;
/**
 *
 * @tparam T The GraphNode Type
 * @tparam U The Edge Weighting
 */
template <typename T,typename U> class GraphVedge {
public:
    GraphVedge(std::shared_ptr<GraphNode<T>> Target);
private:
    std::shared_ptr<GraphNode<T>> Target;
    U weight;
};

#include "GraphNode.hh"

template <typename T,typename U> GraphVedge<T,U>::GraphVedge(std::shared_ptr<GraphNode<T>> Target): Target(Target){

}

#endif //TRAVELLER_GRAPH_GRAPHVEDGE_HH
