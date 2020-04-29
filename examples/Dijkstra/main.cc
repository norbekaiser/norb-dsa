

#include <iostream>

#include "Graph/Graph.hh"

int main(int argc, char** argv)
{
    using std::cout;
    using std::endl;
    cout << "Generating Elements" << endl;
    int a='a',b='b',c='c',d='d';

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
    return 0;



}
