//
// Created by norbert on 28.04.20.
//

#ifndef TRAVELLER_GRAPH_DEPTHFIRSTSEARCHVISIT_HH
#define TRAVELLER_GRAPH_DEPTHFIRSTSEARCHVISIT_HH

#include <memory>

template <typename T> struct DepthFirstSearchStorage;
template <typename T> struct GraphNode;
template <typename T> void DepthFirstSearchVisit(DepthFirstSearchStorage<T> &storage,std::shared_ptr<GraphNode<T>> Node);

#include "GraphNode.hh"
#include "DepthFirstSearchStorage.hh"
#include <algorithm>
template <typename T> void DepthFirstSearchVisit(DepthFirstSearchStorage<T> &storage,std::shared_ptr<GraphNode<T>> Node)
{
    storage.time = storage.time + 1;
    storage.Colors[Node] = storage.gray;
    std::for_each(storage.OnGray.begin(),storage.OnGray.end(),[&Node](auto f){f(Node);});
    for(auto &V: Node->getVedges())
    {
        if(!storage.Colors.contains(Node) || storage.Colors[Node] ==storage.white)
        {
            storage.pi[V.getTarget()] = Node;
            DepthFirstSearchVisit(storage,V.getTarget());
        }
    }
    storage.time = storage.time + 1;
    storage.Colors[Node] = storage.black;
    std::for_each(storage.OnBlack.begin(),storage.OnBlack.end(),[&Node](auto f){f(Node);});




};


#endif //TRAVELLER_GRAPH_DEPTHFIRSTSEARCHVISIT_HH
