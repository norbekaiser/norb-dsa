

#include <iostream>

#include "Graph/Graph.hh"
#include "Graph/TopologicalSort.hh"
int main(int argc, char** argv)
{
    using std::cout;
    using std::endl;
    cout << "Generating Elements" << endl;
    std::string Schuhe="Schuhe",Socken="Socken",Mantel="Mantel",Hose="Hose",Unterhose="Unterhose",Pullover="Pullover",Unterhemd="Unterhemd";

    Graph<std::string> G;
    cout << "Adding Elements to Graph" << endl;

    auto g_ptr_unterhemd = G.addToGraph(Unterhemd);
    auto g_ptr_pullover = G.addToGraph(Pullover);
    auto g_ptr_mantel = G.addToGraph(Mantel);
    auto g_ptr_unterhose = G.addToGraph(Unterhose);
    auto g_ptr_hose = G.addToGraph(Hose);
    auto g_ptr_socken = G.addToGraph(Socken);
    auto g_ptr_schuhe = G.addToGraph(Schuhe);


    cout << "Connecting Nodes as they were all lonely" << endl;
    g_ptr_unterhemd->addEdge(g_ptr_pullover);
    g_ptr_pullover->addEdge(g_ptr_mantel);
    g_ptr_unterhose->addEdge(g_ptr_hose);
    g_ptr_hose->addEdge(g_ptr_mantel);
    g_ptr_hose->addEdge(g_ptr_schuhe);
    g_ptr_socken->addEdge(g_ptr_schuhe);
    cout << "Sorting Topologically" << endl;
    auto List = TopologicalSort<std::string>(G);
    cout << "Let's see how strange we dress us today" << endl;
    for(auto &Node: List)
    {
        cout << Node->getElem() << endl;
    }
    return 0;



}
