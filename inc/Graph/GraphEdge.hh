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

#ifndef LIBNORB_DSA_GRAPHVEDGE_HH
#define LIBNORB_DSA_GRAPHVEDGE_HH

#include <memory>
namespace norbdsa
{
    template <typename T,typename ... U> class GraphNode;
    /**
     *
     * @tparam T
     * @tparam U the weights of
     */
    template <typename T,typename ... U> class GraphEdge {
    public:
        GraphEdge(std::shared_ptr<GraphNode<T>> Target);
        const std::shared_ptr<GraphNode<T>> &getTarget() const;
        const std::tuple<U...> &getWeights() const;
    private:
        std::shared_ptr<GraphNode<T>> Target;
        std::tuple<U...> weights;
    };
}
#include "GraphNode.hh"
namespace norbdsa
{
    template <typename T,typename ... U> GraphEdge<T,U...>::GraphEdge(std::shared_ptr<GraphNode<T>> Target): Target(std::move(Target)){

    }

    template<typename T, typename ... U> const std::shared_ptr<GraphNode<T>> &GraphEdge<T,U...>::getTarget() const {
        return Target;
    }

    template<typename T, typename... U> const std::tuple<U...> &GraphEdge<T, U...>::getWeights() const {
        return weights;
    }
}

#endif //NORB_DSA_GRAPHVEDGE_HH
