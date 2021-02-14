#ifndef INCLUDED_QUEUE_H
#define INCLUDED_QUEUE_H

#include "Queue.h"

template<class TQ>
class Queue
{
private:
    List<TQ> q;
public:
    Queue() : q() {}
    ~Queue() {}

    const unsigned int getSize() const { return q.getSize(); }
    TQ* front() { return q.front(); }
    TQ* back () { return q.back(); }
    void enqueue(TQ data) { q.pushList(data); }
    void dequeue() { q.dequeue(); }
    TQ* operator[](const unsigned int indice) { return q[indice]; }
    const bool empty() const { return q.empty(); }
};

#endif // INCLUDED_QUEUE_H
