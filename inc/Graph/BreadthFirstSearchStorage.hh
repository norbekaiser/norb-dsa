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

#ifndef LIBNORB_DSA_BREADTHFIRSTSEARCHSTORAGE_HH
#define LIBNORB_DSA_BREADTHFIRSTSEARCHSTORAGE_HH

#include <queue>

namespace norbdsa
{
    enum class TraversalColor;
    template < template <typename ,typename...> typename C,typename T,typename ... U> class TraversalColoring;
    template <typename T,typename ... U> class GraphNode;
    template <typename T,typename ... U> class BreadthFirstSearchStorage
    {
    public:
//        struct White,Gray,Black;//dismissed tag dispatch, as unclear for return type and minimizing readability
        TraversalColor getMark(std::shared_ptr<GraphNode<T,U...>> N);
        void mark(std::shared_ptr<GraphNode<T,U...>> N,TraversalColor color);
        void push(std::shared_ptr<GraphNode<T,U...>> N);
        bool q_empty();
        std::shared_ptr<GraphNode<T,U...>> pop();
    private:
        std::queue<std::shared_ptr<GraphNode<T,U...>>> Q;
        TraversalColoring<GraphNode,T,U...> coloring;

    };
}

#include <memory>
#include <functional>
#include "GraphNode.hh"
#include "TraversalColoring.hh"


namespace norbdsa
{
    template<typename T, typename... U> TraversalColor BreadthFirstSearchStorage<T, U...>::getMark(std::shared_ptr<GraphNode<T, U...>> N)
    {
        return coloring.getMark(std::move(N));
    }
    template<typename T, typename... U>  std::shared_ptr<GraphNode<T,U...>> BreadthFirstSearchStorage<T, U...>::pop()
    {
        auto temp = Q.front();
        Q.pop();
        return std::move(temp);
    }

    template<typename T, typename... U> void BreadthFirstSearchStorage<T, U...>::mark(std::shared_ptr<GraphNode<T, U...>> N, TraversalColor color) {
        coloring.setMark(std::move(N),color);
    }

    template<typename T, typename... U> void BreadthFirstSearchStorage<T, U...>::push(std::shared_ptr<GraphNode<T, U...>> N) {
        Q.push(std::move(N));
    }
    template<typename T, typename... U> bool BreadthFirstSearchStorage<T, U...>::q_empty()   {
        return Q.empty();
    }

}

#endif //LIBNORB_DSA_BREADTHFIRSTSEARCHSTORAGE_HH

