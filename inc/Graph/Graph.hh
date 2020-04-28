//
// Created by norbert on 24.04.20.
//

#ifndef TRAVELLER_GRAPH_GRAPH_HH
#define TRAVELLER_GRAPH_GRAPH_HH

#include <memory>
#include <vector>
#include <unordered_map>

template <typename T> class GraphNode;
template <typename T> class Graph
{
private:
    std::vector<std::shared_ptr<GraphNode<T>>> Nodes;
public:
    std::shared_ptr<GraphNode<T>> addToGraph(T Elem);
    std::shared_ptr<GraphNode<T>> addNode(std::shared_ptr<GraphNode<T>> Node);
    std::vector<std::shared_ptr<GraphNode<T>>> getNodes();
};

#include "GraphNode.hh"

template <typename T> std::shared_ptr<GraphNode<T>> Graph<T>::addToGraph(T Elem)
{
    auto ptr = std::make_shared<GraphNode<T>>(Elem);
    return addNode(std::move(ptr));
}
//todo make sure it only exists once or so, e.g. map?
template <typename T> std::shared_ptr<GraphNode<T>> Graph<T>::addNode(std::shared_ptr<GraphNode<T>> Node) {
    Nodes.push_back(Node);
    return Node;
}

template <typename T> std::vector<std::shared_ptr<GraphNode<T>>> Graph<T>::getNodes() {
    return Nodes;
}

#endif //TRAVELLER_GRAPH_GRAPH_HH
