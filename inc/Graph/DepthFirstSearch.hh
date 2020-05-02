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

namespace norbdsa
{
    template <typename T,typename ... U> class Graph;
    template <typename T,typename ... U> struct DepthFirstSearchStorage;
    /**
     *
     * @tparam T
     * @tparam U
     * @param G
     */
    template <typename T,typename ... U> void DepthFirstSearch(Graph<T,U...> G);
    /**
     *
     * @tparam T
     * @tparam U
     * @param G
     * @param storage
     */
    template <typename T,typename ... U> void DepthFirstSearch(Graph<T,U...> G,DepthFirstSearchStorage<T,U...> &storage);

}

#include <memory>
#include "Graph.hh"
#include "DepthFirstSearchVisit.hh"
#include "DepthFirstSearchStorage.hh"

namespace norbdsa
{
    template <typename T,typename ... U> void DepthFirstSearch(Graph<T,U...> G)
    {
        DepthFirstSearchStorage<T> DFSS;
        DepthFirstSearch(std::move(G),DFSS);
    };

    template <typename T,typename ... U> void DepthFirstSearch(Graph<T,U...> G,DepthFirstSearchStorage<T,U...> &storage)
    {
        for(auto &Node: G.getNodes())
        {
            storage.Colors[Node] = storage.white;
        }
        storage.time=0;
        for(auto &Node: G.getNodes())
        {
            if(!storage.Colors.contains(Node) || storage.Colors[Node]==storage.white)
            {
                DepthFirstSearchVisit(storage,Node);
            }
        }
    };
}

#endif //NORB_DSA_DEPTHFIRSTSEARCH_HH
