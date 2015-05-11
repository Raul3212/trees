#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"
#include <list>
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
class BinaryTree
{

protected:
    INode<T>* raiz{NULL};

public:
    BinaryTree();
    virtual ~BinaryTree();
    unsigned int getQntNodes() const;
    list<T> getInOrder() const;
    list<T> getPreOrder() const;
    list<T> getPosOrder() const;
    void printInOrder()const;
    static string vectorToString(list<T> v);

protected:
    unsigned int countNodes(const INode<T>* raiz) const;
    list<T> inOrder(const INode<T>* raiz) const;
    list<T> preOrder(const INode<T>* raiz) const;
    list<T> posOrder(const INode<T>* raiz) const;
    void printInOrder(INode<T>* raiz) const;

    virtual bool insert(T value) = 0;
    virtual bool remove(T value) = 0;
    virtual INode<T>* search(T value) = 0;

private:
    list<INode<T>*> getAllNodeReferences(INode<T>* raiz) const;

};


#endif // BINARYTREE_H
