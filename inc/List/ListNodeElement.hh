
#ifndef NORB_DSA_LISTNODEELEMENT_HH
#define NORB_DSA_LISTNODEELEMENT_HH


template <typename T> class ListNodeElement
{
public:
    virtual ListNodeElement<T>* add(T Elem)=0;
    virtual int size()=0;
};



#endif //NORB_DSA_LISTNODEELEMENT_HH
