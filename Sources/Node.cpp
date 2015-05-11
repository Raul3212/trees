#include "Node.h"

template <typename T>
Node<T>::Node(T value) : INode<T>::INode(value)
{}

template <typename T>
Node<T>::~Node()
{
    delete this->right;
    delete this->left;
}

template class Node<double>;
