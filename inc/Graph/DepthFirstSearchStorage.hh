
#ifndef NORB_DSA_DEPTHFIRSTSEARCHSTORAGE_HH
#define NORB_DSA_DEPTHFIRSTSEARCHSTORAGE_HH


template <typename T> class GraphNode;
template <typename T> struct DepthFirstSearchStorage;

#include <memory>
#include <unordered_map>
#include <functional>
#include "GraphNode.hh"

template <typename T> struct DepthFirstSearchStorage{
    enum color{white,gray,black};
    std::unordered_map<std::shared_ptr<GraphNode<T>>,color> Colors;
    std::unordered_map<std::shared_ptr<GraphNode<T>>,std::shared_ptr<GraphNode<T>>> pi;
    std::vector<std::function<void(std::shared_ptr<GraphNode<T>>)>> OnBlack;
    std::vector<std::function<void(std::shared_ptr<GraphNode<T>>)>> OnGray;
    long time=0;
};


#endif //NORB_DSA_DEPTHFIRSTSEARCHSTORAGE_HH
