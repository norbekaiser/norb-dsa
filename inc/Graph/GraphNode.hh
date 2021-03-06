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

#ifndef LIBNORB_DSA_GRAPHNODE_HH
#define LIBNORB_DSA_GRAPHNODE_HH

#include <vector>
#include <memory>
namespace norbdsa
{
    template <typename T, typename ... U> class GraphEdge;
    /**
     *
     * @tparam T
     * @tparam U
     */
    template <typename T, typename ... U> class GraphNode
    {
    public:
        GraphNode(T Elem);
        GraphEdge<T,U...> addEdge(std::shared_ptr<GraphNode<T,U...>> Target);
        const std::vector<GraphEdge<T,U...>> &getEdges() const;
        T getElem() const;
    private:
        T Elem;
        std::vector<GraphEdge<T,U...>> Edges;

    };
}
#include "GraphEdge.hh"
namespace norbdsa
{
    template <typename T, typename ... U> GraphNode<T,U...>::GraphNode(T Elem): Elem(Elem)
    {

    }

    template <typename T, typename ... U> GraphEdge<T,U...> GraphNode<T,U...>::addEdge(std::shared_ptr<GraphNode<T,U...>> Target)
    {
        GraphEdge<T,U...> Edge(std::move(Target));
        this->Edges.push_back(Edge);
        return Edge;
    }

    template<typename T, typename ... U> const std::vector<GraphEdge<T,U...>> &GraphNode<T,U...>::getEdges() const
    {
        return Edges;
    }

    template<typename T, typename ... U> T GraphNode<T,U...>::getElem() const
    {
        return Elem;
    }
}

#endif //NORB_DSA_GRAPHNODE_HH
