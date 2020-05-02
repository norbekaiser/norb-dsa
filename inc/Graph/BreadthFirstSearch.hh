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

#ifndef LIBNORB_DSA_BREADTHFIRSTSEARCH_HH
#define LIBNORB_DSA_BREADTHFIRSTSEARCH_HH

#include <memory>

namespace norbdsa
{
    template <typename T,typename ... U> class Graph;
    template <typename T,typename ... U> class GraphNode;
    template <typename T,typename ... U> struct BreadthFirstSearchStorage;
    /**
     *
     * @tparam T
     * @tparam U
     * @param G
     * @param S
     */
    template <typename T,typename ... U> void BreadthFirstSearch(Graph<T,U...> G,std::shared_ptr<GraphNode<T,U...>> S);
    /**
     *
     * @tparam T
     * @tparam U
     * @param G
     * @param S
     * @param storage
     */
    template <typename T,typename ... U> void BreadthFirstSearch(Graph<T,U...> G,std::shared_ptr<GraphNode<T,U...>> S,BreadthFirstSearchStorage<T,U...> &storage);
};

#include "Graph.hh"
#include "GraphNode.hh"
#include "BreadthFirstSearchStorage.hh"
#include <queue>

namespace norbdsa
{
    template <typename T,typename ... U> void BreadthFirstSearch(Graph<T,U...> G,std::shared_ptr<GraphNode<T,U...>> S)
    {
        BreadthFirstSearchStorage<T> BFSS;
        BreadthFirstSearch(std::move(G),std::move(S),BFSS);
    }

    template <typename T,typename ... U> void BreadthFirstSearch(Graph<T,U...> G,std::shared_ptr<GraphNode<T,U...>> S,BreadthFirstSearchStorage<T,U...> &storage)
    {
        for(auto &Node: G.getNodes())
        {
            storage.Colors[Node] = storage.white;
        }
        storage.Colors[S] = storage.gray;

        std::queue<std::shared_ptr<GraphNode<T,U...>>> Q;
        Q.push(S);
        while(!Q.empty())
        {
            std::shared_ptr<GraphNode<T,U...>> node = Q.front();
            Q.pop();
            //for all adjacent vertexes
            for(auto &Edge: S->getEdges())
            {
                if(!storage.Colors.contains(Edge.getTarget()) || storage.Colors[Edge.getTarget()]==storage.white)
                {
                    storage.Colors[Edge.getTarget()] = storage.gray;
                    Q.push(Edge.getTarget());
                }
            }
            storage.Colors[node] = storage.black;
        }

    }
}


#endif //LIBNORB_DSA_BREADTHFIRSTSEARCH_HH
