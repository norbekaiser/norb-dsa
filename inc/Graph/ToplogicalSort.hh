//
// Created by norbert on 28.04.20.
//

#ifndef TRAVELLER_GRAPH_TOPLOGICALSORT_HH
#define TRAVELLER_GRAPH_TOPLOGICALSORT_HH

#include <deque>
#include <memory>


template <typename T> class Graph;
template <typename T> class GraphNode;
template <typename T> std::vector<std::shared_ptr<GraphNode<T>>> TopologicalSort(Graph<T> G);


#include "Graph/Graph.hh"
#include "Graph/GraphNode.hh"
#include "Graph/DepthFirstSearch.hh"

template <typename T> std::vector<std::shared_ptr<GraphNode<T>>> TopologicalSort(Graph<T> G)
{
    DepthFirstSearchStorage<T> DFSS;
    std::vector<std::shared_ptr<GraphNode<T>>> List;
    DFSS.OnBlack.push_back(std::move(
            [&List](std::shared_ptr<GraphNode<T>> Node){
                List.push_back(Node);
            }));
    DepthFirstSearch(G,DFSS);
    return List;

}

#endif //TRAVELLER_GRAPH_TOPLOGICALSORT_HH
