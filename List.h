#ifndef INCLUDED_LIST_H
#define INCLUDED_LIST_H

#include <stdio.h>

template <class TL> class List {
private:
    template <class TE> class Element {
    private:
        TE data;
        Element<TE>* next;
        Element<TE>* prev;

    public:
        Element();
        ~Element();

        void setNext(Element* e);
        Element* getNext() const;
        void setPrev(Element* e);
        Element* getPrev() const;
        void setData(TE d);
        TE* getData();
    };

private:
    unsigned int size;
    Element<TL>* first;
    Element<TL>* last;

public:
    List();
    ~List();

    const unsigned int getSize() const;
    TL* front();
    TL* back();

    void insertList(TL d);
    void pushList(TL d);
    void eraseList(const unsigned int indice);
    void dequeue();
    void pop();
    TL* operator[](const unsigned int indice);
    const bool empty() const;

};

///---------- ELEMENT ----------///

template<class TL>
template<class TE>
List<TL>::Element<TE>::Element()
{
    next = NULL;
    prev = NULL;
}

template<class TL>
template<class TE>
List<TL>::Element<TE>::~Element()
{
    next = NULL;
    prev = NULL;
}

template<class TL>
template<class TE>
void List<TL>::Element<TE>::setNext(Element* e)
{
    next = e;
}

template<class TL>
template<class TE>
List<TL>::Element<TE>* List<TL>::Element<TE>::getNext() const
{
    return next;
}

template<class TL>
template<class TE>
void List<TL>::Element<TE>::setPrev(Element* e)
{
    prev = e;
}

template<class TL>
template<class TE>
List<TL>::Element<TE>* List<TL>::Element<TE>::getPrev() const
{
    return prev;
}

template<class TL>
template<class TE>
void List<TL>::Element<TE>::setData(TE d)
{
    data = d;
}

template<class TL>
template<class TE>
TE* List<TL>::Element<TE>::getData()
{
    return &data;
}

///---------- List ----------///

template<class TL>
List<TL>::List() :
    size(0)
{
    first = NULL;
    last = NULL;
}

template<class TL>
List<TL>::~List()
{
    Element<TL>* aux = first;
    while(aux != NULL)
    {
        first = first->getNext();
        delete aux;
        aux = first;
    }
    size = 0;
    first = NULL;
    last = NULL;
}

template<class TL>
const unsigned int List<TL>::getSize() const
{
    return size;
}

template<class TL>
TL* List<TL>::front()
{
    return (first != NULL ? first->getData() : NULL);
}

template<class TL>
TL* List<TL>::back()
{
    return (last != NULL ? last->getData() : NULL);
}

template<class TL>
void List<TL>::insertList(TL d)
{
    size++;
    Element<TL>* aux = new Element<TL>();
    aux->setData(d);
    if(first == NULL) {
        first = aux;
        last  = aux;
    } else {
        aux->setNext(first);
        first->setPrev(aux);
        first = aux;
    }
}

template<class TL>
void List<TL>::pushList(TL d)
{
    size++;
    Element<TL>* aux = new Element<TL>();
    aux->setData(d);
    if(last == NULL) {
        first = aux;
        last  = aux;
    } else {
        aux->setPrev(last);
        last->setNext(aux);
        last = aux;
    }
}

template<class TL>
void List<TL>::eraseList(const unsigned int indice)
{
    unsigned int j = 0;
    Element<TL>* aux1 = first;
    Element<TL>* aux2 = NULL;
    while(aux1 != NULL && indice != j) {
        aux2 = aux1;
        aux1 = aux1->getNext();
        j++;
    }
    if(aux2 == NULL) {
        if(aux1 != NULL) {
            first = aux1->getNext();
            delete aux1;
            if(first != NULL) {
                first->setPrev(NULL);
            }
        }
    } else if(aux1 != NULL) {
        aux2->setNext(aux1->getNext());
        if(aux1->getNext() != NULL) {
            aux1->getNext()->setPrev(aux2);
        }
        delete aux1;
    }
}

template<class TL>
void List<TL>::dequeue()
{
    size--;
    Element<TL>* aux = first;
    first = first->getNext();
    delete aux;
    if(first != NULL) {
        first->setPrev(NULL);
    } else {
        last = NULL;
    }
}

template<class TL>
void List<TL>::pop()
{
    size--;
    Element<TL>* aux = last;
    last = last->getPrev();
    delete aux;
    if(last != NULL) {
        last->setNext(NULL);
    } else {
        first = NULL;
    }
}

template<class TL>
TL* List<TL>::operator[](const unsigned int indice)
{
    Element<TL>* aux = first;
    unsigned int j = 0;
    while(aux != NULL && indice != j) {
        aux = aux->getNext();
        j++;
    }
    if(aux != NULL) {
        return (aux->getData());
    }
    return NULL;
}

template<class TL>
const bool List<TL>::empty() const
{
    return (size == 0 ? true : false);
}

#endif // INCLUDED_LIST_H
