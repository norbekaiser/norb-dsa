
#ifndef TRAVELLER_GRAPH_GRAPHVEDGE_HH
#define TRAVELLER_GRAPH_GRAPHVEDGE_HH



template <typename T> class GraphNode;
template <typename T> class GraphVedge {
public:
    GraphVedge(T Target);

private:
    GraphNode<T> Target;
};

#include "GraphNode.hh"

template <typename T> GraphVedge<T>::GraphVedge(T Elem) {

}

#endif //TRAVELLER_GRAPH_GRAPHVEDGE_HH
