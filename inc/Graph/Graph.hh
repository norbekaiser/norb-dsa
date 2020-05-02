// Copyright (c) 2020 Norbert Rühl
//
// This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
//
//     1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
//
//     2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
//
//     3. This notice may not be removed or altered from any source distribution.

#ifndef NORB_DSA_GRAPH_HH
#define NORB_DSA_GRAPH_HH

#include <memory>
#include <vector>

template <typename T,typename ... U> class GraphNode;
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

template <typename T> std::shared_ptr<GraphNode<T>> Graph<T>::addNode(std::shared_ptr<GraphNode<T>> Node) {
    Nodes.push_back(Node);
    return Node;
}

template <typename T> std::vector<std::shared_ptr<GraphNode<T>>> Graph<T>::getNodes() {
    return Nodes;
}

#endif //NORB_DSA_GRAPH_HH
