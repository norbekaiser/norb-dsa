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

#ifndef LIBNORB_DSA_LIST_HH
#define LIBNORB_DSA_LIST_HH

#include <List/ListNodeElement.hh>
#include <List/ListNodeEnd.hh>

template <typename T> class List
{
public:
    List();
    void addToList(T Elem);
    int size();

private:
    ListNodeElement<T>* start;
};

template <typename T> List<T>::List() {
    start = new ListNodeEnd<T>();
}

template <typename T> void List<T>::addToList(T Elem) {
    start = start->add(Elem);
}

template <typename T> int List<T>::size() {
    return start->size();
}



#endif //NORB_DSA_LIST_HH
