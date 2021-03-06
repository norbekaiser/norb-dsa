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

#ifndef LIBNORB_DSA_TOPOLOGICALSORT_HH
#define LIBNORB_DSA_TOPOLOGICALSORT_HH

#include <deque>
#include <memory>

namespace norbdsa
{
    template <typename T, typename ... U> class Graph;
    template <typename T, typename ... U> class GraphNode;
    /**
     *
     * @tparam T
     * @tparam U
     * @param G
     * @return
     */
    template <typename T, typename ... U> std::deque<std::shared_ptr<GraphNode<T,U...>>> TopologicalSort(Graph<T,U...> G);
}

#include "Graph.hh"
#include "GraphNode.hh"
#include "DepthFirstSearch.hh"
namespace norbdsa
{
    template <typename T,typename ... U> std::deque<std::shared_ptr<GraphNode<T,U...>>> TopologicalSort(Graph<T,U...> G)
    {
        DepthFirstSearchStorage<T> DFSS;
        std::deque<std::shared_ptr<GraphNode<T>>> List;
        DFSS.OnBlack.push_back(std::move(
                [&List](std::shared_ptr<GraphNode<T>> Node){
                    List.push_front(Node);
                }));
        DepthFirstSearch(G,DFSS);
        return List;

    }
}

#endif //NORB_DSA_TOPOLOGICALSORT_HH
