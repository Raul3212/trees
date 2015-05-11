#ifndef NODE_H
#define NODE_H

#include "INode.h"
#include <iostream>

using namespace std;

template <typename T>
class Node : public INode<T>
{
public:
    Node(T value);
    ~Node();
};

#endif // NODE_H
