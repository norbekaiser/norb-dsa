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

#include <iostream>

#include "Graph/Graph.hh"
#include "Graph/DepthFirstSearch.hh"

/**
 * @example DepthFirstSearch.cc "DepthFirstSearch"
 */

int main(int argc, char** argv)
{

    using std::cout;
    using std::endl;
    using norbdsa::Graph;
    using norbdsa::DepthFirstSearch;
    cout << "Generating Elements" << endl;
    char u,v,x,y,w,z;
    u='u';v='v';x='x';y='y';w='w';z='z';
    Graph<decltype(u)> G;
    cout << "Adding Elements to Graph" << endl;
    auto g_ptr_u = G.addToGraph(u);
    auto g_ptr_v = G.addToGraph(v);
    auto g_ptr_w = G.addToGraph(w);
    auto g_ptr_x = G.addToGraph(x);
    auto g_ptr_y = G.addToGraph(y);
    auto g_ptr_z = G.addToGraph(z);
    cout << "Connecting Nodes as they were all lonely" << endl;
    //u -> v
    g_ptr_u->addEdge(g_ptr_v);
    //u -> x
    g_ptr_u->addEdge(g_ptr_x);
    //v -> y
    g_ptr_v->addEdge(g_ptr_y);
    //y -> x
    g_ptr_y->addEdge(g_ptr_x);
    //x -> v
    g_ptr_x->addEdge(g_ptr_v);
    //w -> z
    g_ptr_w->addEdge(g_ptr_z);
    //w -> y
    g_ptr_w->addEdge(g_ptr_y);
    //z -> z
    g_ptr_z->addEdge(g_ptr_z);
    cout << "Depth First Search" << endl;
    DepthFirstSearch<decltype(u)>(G);
    return 0;



}
