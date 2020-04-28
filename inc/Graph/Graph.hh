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
    void DepthFirstSearch(std::shared_ptr<GraphNode<T>> start);
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

template <typename T> void Graph<T>::DepthFirstSearch(std::shared_ptr<GraphNode<T>> start)
{
    //Storing a Color for hopefully each node
    enum Color {white,gray};
    std::unordered_map<decltype(start),Color> Colors;
    std::unordered_map<decltype(start),decltype(start)> pi;
    for(auto &Node : Nodes)
    {
        Colors[Node] = white;
    }
    long time = 0;
    for(auto &Node: Nodes)
    {
        auto  dfsvisit = [this,&time,&Colors,&pi](decltype(start) u){
            time++;
            //Time[u] = time
            Colors[u] = gray;
            //foreach vertice

        };
        if(Colors.at(Node) ==white)
        {
            dfsvisit(Node);
        }

    }
    
}

#endif //TRAVELLER_GRAPH_GRAPH_HH
