//
// Created by norbert on 23.04.20.
//

#ifndef TRAVELLER_GRAPH_LISTNODE_HH
#define TRAVELLER_GRAPH_LISTNODE_HH

#include <List/ListNodeElement.hh>

template <typename T> class ListNode: public ListNodeElement<T>
{

public:
    ListNode(T Elem,ListNodeElement<T> *Next);
    ListNodeElement<T>* add(T Elem);
    int size();

private:
    T ref;
    ListNodeElement<T> *next;
};


template <typename T> ListNode<T>::ListNode(T Elem, ListNodeElement<T> *Next) {
//    this->ref = Elem;
    this->next = Next;
}

template <typename T> ListNodeElement<T>* ListNode<T>::add(T Elem) {
    next = next->add(Elem);
    return this;
}

template <typename T> int ListNode<T>::size() {
    return 1 + next->size();
}
#endif //TRAVELLER_GRAPH_LISTNODE_HH
