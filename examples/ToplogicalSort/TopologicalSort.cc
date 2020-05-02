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
#include <Graph/Graph.hh>
#include <Graph/TopologicalSort.hh>

enum class Cloth
{
    Schuhe,
    Socken,
    Mantel,
    Hose,
    Unterhose,
    Pullover,
    Unterhemd,
    Brille
};

std::ostream & operator<<(std::ostream& os,const Cloth cloth)
{
    switch(cloth)
    {
        case Cloth::Schuhe: return os << "Schuhe";
        case Cloth::Socken: return os << "Socken";
        case Cloth::Mantel: return os << "Mantel";
        case Cloth::Hose: return os << "Hose";
        case Cloth::Unterhose: return os << "Unterhose";
        case Cloth::Pullover: return os << "Pullover";
        case Cloth::Unterhemd: return os << "Unterhemd";
        case Cloth::Brille: return os << "Brille";
    }

    return os;
}

/**
 * @example TopologicalSort.cc "Topological Sort Example"
 * This Example Topological Sorts Cloths
 *
 */
int main(int argc, char** argv)
{
    using std::cout;
    using std::endl;
    using norbdsa::Graph;
    using norbdsa::TopologicalSort;
    cout << "Adding Graph" << endl;
    Graph<Cloth> G;
    cout << "Adding Elements to Graph" << endl;
    auto g_ptr_unterhemd = G.addToGraph(Cloth::Unterhemd);
    auto g_ptr_unterhose = G.addToGraph(Cloth::Unterhose);
    auto g_ptr_socken = G.addToGraph(Cloth::Socken);
    auto g_ptr_pullover = G.addToGraph(Cloth::Pullover);
    G.addToGraph(Cloth::Brille);
    auto g_ptr_hose = G.addToGraph(Cloth::Hose);
    auto g_ptr_schuhe = G.addToGraph(Cloth::Schuhe);
    auto g_ptr_mantel = G.addToGraph(Cloth::Mantel);
    cout << "Connecting Nodes as they were all lonely" << endl;
    g_ptr_unterhemd->addEdge(g_ptr_pullover);
    g_ptr_pullover->addEdge(g_ptr_mantel);
    g_ptr_unterhose->addEdge(g_ptr_hose);
    g_ptr_hose->addEdge(g_ptr_mantel);
    g_ptr_hose->addEdge(g_ptr_schuhe);
    g_ptr_socken->addEdge(g_ptr_schuhe);
    cout << "Sorting Topologically" << endl;
    auto List = TopologicalSort<Cloth>(G);
    cout << "Let's see how strange we dress us today" << endl;
    for(auto &Node: List)
    {
        cout << Node->getElem() << endl;
    }
    return 0;
}
