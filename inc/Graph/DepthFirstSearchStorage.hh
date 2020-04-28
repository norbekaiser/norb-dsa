//
// Created by norbert on 28.04.20.
//

#ifndef TRAVELLER_GRAPH_DEPTHFIRSTSEARCHSTORAGE_HH
#define TRAVELLER_GRAPH_DEPTHFIRSTSEARCHSTORAGE_HH

#include <memory>
#include <unordered_map>

template <typename T> class GraphNode;
template <typename T> struct DepthFirstSearchStorage;

#include "GraphNode.hh"

template <typename T> struct DepthFirstSearchStorage{
    enum color{white,gray,black};
    std::unordered_map<std::shared_ptr<GraphNode<T>>,color> Colors;
    std::unordered_map<std::shared_ptr<GraphNode<T>>,std::shared_ptr<GraphNode<T>>> pi;
    long time=0;
};


#endif //TRAVELLER_GRAPH_DEPTHFIRSTSEARCHSTORAGE_HH
