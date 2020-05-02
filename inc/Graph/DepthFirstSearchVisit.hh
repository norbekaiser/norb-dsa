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

#ifndef LIBNORB_DSA_DEPTHFIRSTSEARCHVISIT_HH
#define LIBNORB_DSA_DEPTHFIRSTSEARCHVISIT_HH

#include <memory>

template <typename T> struct DepthFirstSearchStorage;
template <typename T,typename ... U> struct GraphNode;
template <typename T> void DepthFirstSearchVisit(DepthFirstSearchStorage<T> &storage,std::shared_ptr<GraphNode<T>> Node);

#include "GraphNode.hh"
#include "DepthFirstSearchStorage.hh"
#include <algorithm>
template <typename T> void DepthFirstSearchVisit(DepthFirstSearchStorage<T> &storage,std::shared_ptr<GraphNode<T>> Node)
{
    storage.time = storage.time + 1;
    storage.Colors[Node] = storage.gray;
    std::for_each(storage.OnGray.begin(),storage.OnGray.end(),[&Node](auto f){f(Node);});
    for(auto &V: Node->getVedges())
    {
        if(!storage.Colors.contains(V.getTarget()) || storage.Colors[V.getTarget()] ==storage.white)
        {
            storage.pi[V.getTarget()] = Node;
            DepthFirstSearchVisit(storage,V.getTarget());
        }
    }
    storage.time = storage.time + 1;
    storage.Colors[Node] = storage.black;
    std::for_each(storage.OnBlack.begin(),storage.OnBlack.end(),[&Node](auto f){f(Node);});




};


#endif //NORB_DSA_DEPTHFIRSTSEARCHVISIT_HH
