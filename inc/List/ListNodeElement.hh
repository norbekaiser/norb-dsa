//
// Created by norbert on 23.04.20.
//

#ifndef TRAVELLER_GRAPH_LISTNODEELEMENT_HH
#define TRAVELLER_GRAPH_LISTNODEELEMENT_HH


template <typename T> class ListNodeElement
{
public:
    virtual ListNodeElement<T>* add(T Elem)=0;
    virtual int size()=0;
};



#endif //TRAVELLER_GRAPH_LISTNODEELEMENT_HH
