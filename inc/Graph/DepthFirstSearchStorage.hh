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

#ifndef LIBNORB_DSA_DEPTHFIRSTSEARCHSTORAGE_HH
#define LIBNORB_DSA_DEPTHFIRSTSEARCHSTORAGE_HH

namespace norbdsa
{
    template <typename T,typename ... U> class GraphNode;
    /**
     *
     * @tparam T
     * @tparam U
     */
    template <typename T,typename ... U> struct DepthFirstSearchStorage;
}

#include <memory>
#include <unordered_map>
#include <functional>
#include "GraphNode.hh"

namespace norbdsa
{
    template <typename T,typename ... U> struct DepthFirstSearchStorage
    {
        enum color{white,gray,black};
        std::unordered_map<std::shared_ptr<GraphNode<T,U...>>,color> Colors;
        std::unordered_map<std::shared_ptr<GraphNode<T,U...>>,std::shared_ptr<GraphNode<T>>> pi;
        std::vector<std::function<void(std::shared_ptr<GraphNode<T,U...>>)>> OnBlack;
        std::vector<std::function<void(std::shared_ptr<GraphNode<T,U...>>)>> OnGray;
        long time=0;
    };
}

#endif //NORB_DSA_DEPTHFIRSTSEARCHSTORAGE_HH
