//
// Created by norbert on 23.04.20.
//

#ifndef TRAVELLER_GRAPH_LISTNODEEND_HH
#define TRAVELLER_GRAPH_LISTNODEEND_HH

#include <List/ListNodeElement.hh>
#include <List/ListNode.hh>

template <typename T> class ListNodeEnd: public ListNodeElement<T>
{
public:
    ListNodeElement<T>* add(T Elem);
    int size();
};

template <typename T> ListNodeElement<T>* ListNodeEnd<T>::add(T Elem) {
    ListNodeElement<T>* next = new ListNode<T>(Elem,this);
    return next;
}

template <typename T> int ListNodeEnd<T>::size() {
    return 0;
}
#endif //TRAVELLER_GRAPH_LISTNODEEND_HH
