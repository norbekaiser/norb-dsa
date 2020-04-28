//
// Created by norbert on 28.04.20.
//

#ifndef TRAVELLER_GRAPH_DEPTHFIRSTSEARCH_HH
#define TRAVELLER_GRAPH_DEPTHFIRSTSEARCH_HH



template <typename T> class Graph;
template <typename T> void DepthFirstSearch(Graph<T> G);

#include <memory>
#include "Graph.hh"
#include "DepthFirstSearchVisit.hh"
#include "DepthFirstSearchStorage.hh"

template <typename T> void DepthFirstSearch(Graph<T> G)
{

    DepthFirstSearchStorage<T> storage;
    for(auto &Node: G.getNodes())
    {
        storage.Colors[Node] = storage.white;
    }
    storage.time=0;
    for(auto &Node: G.getNodes())
    {
        if(!storage.Colors.contains(Node) || storage.Colors[Node]==storage.white){
            DepthFirstSearchVisit(storage,Node);
        }
    }



};


#endif //TRAVELLER_GRAPH_DEPTHFIRSTSEARCH_HH
