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

int main(int argc, char** argv)
{
    using std::cout;
    using std::endl;
    cout << "Generating Elements" << endl;
    char a='a',b='b',c='c',d='d';
    Graph<decltype(a)> G;
    cout << "Adding Elements to Graph" << endl;
    auto g_ptr_a = G.addToGraph(a);
    auto g_ptr_b = G.addToGraph(b);
    auto g_ptr_c = G.addToGraph(c);
    auto g_ptr_d = G.addToGraph(d);
    cout << "Connecting Nodes as they were all lonely" << endl;
    g_ptr_a->addEdge(g_ptr_d);
    g_ptr_a->addEdge(g_ptr_b);
    g_ptr_b->addEdge(g_ptr_c);
    g_ptr_d->addEdge(g_ptr_c);
    //feature not yet implemented
    return 0;



}
