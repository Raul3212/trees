/*
 * AVLTree.h
 *
 *  Created on: 15/04/2015
 *      Author: raul
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "AVLNode.h"
#include "BSTree.h"
#include <cmath>
#include <list>

template <typename T>
class AVLTree: public BSTree<T> {
public:
	AVLTree();
	AVLTree(list<T> values);
	virtual ~AVLTree();

	bool insert(T value);
	bool remove(T value);

private:
    list<AVLNode<T>*> getAllNodeReferences(AVLNode<T>* raiz) const;
	AVLNode<T>* simpleLeftRotation(AVLNode<T>* node);
	AVLNode<T>* simpleRightRotation(AVLNode<T>* node);
	AVLNode<T>* doubleLeftRotation(AVLNode<T>* node);
	AVLNode<T>* doubleRightRotation(AVLNode<T>* node);
};

#endif /* AVLTREE_H_ */
