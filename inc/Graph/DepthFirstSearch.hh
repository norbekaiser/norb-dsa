
#ifndef NORB_DSA_DEPTHFIRSTSEARCH_HH
#define NORB_DSA_DEPTHFIRSTSEARCH_HH



template <typename T> class Graph;
template <typename T> struct DepthFirstSearchStorage;
template <typename T> void DepthFirstSearch(Graph<T> G);
template <typename T> void DepthFirstSearch(Graph<T> G,DepthFirstSearchStorage<T> &storage);


#include <memory>
#include "Graph.hh"
#include "DepthFirstSearchVisit.hh"
#include "DepthFirstSearchStorage.hh"

template <typename T> void DepthFirstSearch(Graph<T> G)
{
    DepthFirstSearchStorage<T> DFSS;
    DepthFirstSearch(std::move(G),DFSS);
};

template <typename T> void DepthFirstSearch(Graph<T> G,DepthFirstSearchStorage<T> &storage)
{
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


#endif //NORB_DSA_DEPTHFIRSTSEARCH_HH
