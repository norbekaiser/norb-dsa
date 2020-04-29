
#ifndef NORB_DSA_LIST_HH
#define NORB_DSA_LIST_HH

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
