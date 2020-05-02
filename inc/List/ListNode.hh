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

#ifndef LIBNORB_DSA_LISTNODE_HH
#define LIBNORB_DSA_LISTNODE_HH

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
#endif //NORB_DSA_LISTNODE_HH
