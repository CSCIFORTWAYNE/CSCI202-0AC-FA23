#ifndef NODE_H
#define NODE_H

template <class type>
struct node
{
    type *data;
    node<type> *link;
    ~node()
    {
        delete data;
    }
};

#endif