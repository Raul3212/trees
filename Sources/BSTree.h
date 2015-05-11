#ifndef BST_H
#define BST_H

#include "BinaryTree.h"
#include <stack>

using namespace std;

template <typename T>
class BSTree : public BinaryTree<T>
{

public:
    BSTree();
    BSTree(list<T> values);
    ~BSTree();
    virtual bool insert(T value);
    virtual bool remove(T value);
    virtual bool contains(T value) const;
    unsigned int getAlura();
    unsigned int getAlura(T value);
    unsigned int getNivel(T value);
    T getMenor() const;
    T getMaior() const;

protected:
    INode<T>* getMenor(INode<T> *raiz) const;
    INode<T>* getMaior(INode<T> *raiz) const;
    INode<T>* getAntecessor(const INode<T> *raiz) const;
    INode<T>* getSucessor(const INode<T> *raiz) const;
    virtual INode<T>* search(T value);
    unsigned int getAltura(const INode<T> *node);
    unsigned int getNivel(const INode<T>* node);

private:
    list<Node<T>*> getAllNodeReferences(Node<T>* raiz) const;

};


#endif // BST_H
