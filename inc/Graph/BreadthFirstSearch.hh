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
     * Breadth First Search Traverses the Graph starting with a Node S in the breadth
     * @tparam T VertexType
     * @tparam U EdgeWeight
     * @param G Graph<T,U...>
     * @param S Starting Node
     * @param storage storage class, to e.g. get adhoc notified e.g. on grey/visist etc
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
            storage.mark(Node,TraversalColor::White);
        }
        storage.mark(S,TraversalColor::Gray);
        storage.push(S);
        while(!storage.q_empty())
        {
            std::shared_ptr<GraphNode<T,U...>> Node = storage.pop();
            for(auto &Edge: S->getEdges())
            {
                auto V = Edge.getTarget();
                if(storage.getMark(V) == TraversalColor::White)
                {
                    storage.mark(V,TraversalColor::Gray);
                    storage.push(V);
                }
            }
            storage.mark(Node,TraversalColor::Black);
        }
    }
}


#endif //LIBNORB_DSA_BREADTHFIRSTSEARCH_HH
