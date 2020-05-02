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

#ifndef LIBNORB_DSA_LISTNODEEND_HH
#define LIBNORB_DSA_LISTNODEEND_HH

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
#endif //NORB_DSA_LISTNODEEND_HH
