

#include <iostream>

#include "Graph/Graph.hh"
#include "Graph/DepthFirstSearch.hh"

int main(int argc, char** argv)
{
    using std::cout;
    using std::endl;
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
