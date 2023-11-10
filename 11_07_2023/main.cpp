#include <iostream>
#include "arrayQueue.h"
#include "linkedQueue.h"
#include "fakepriorityqueue.h"

int main()
{
    arrayQueue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    try
    {
        q.enqueue(6);
    }
    catch (std::overflow_error e)
    {
        std::cerr << e.what() << '\n';
    }
    int x = q.dequeue();
    q.enqueue(6);

    arrayQueue<int> r(q);
    arrayQueue<int> p;
    p = q;

    fakepriorityqueue<int> lq;
    lq.enqueue(1);
    lq.enqueue(2);
    x = lq.dequeue();
    linkedQueue<int> lq1(lq);
    linkedQueue<int> lq2;
    lq2 = lq;
    return 0;
}