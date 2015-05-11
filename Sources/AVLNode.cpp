/*
 * NodeDE.cpp
 *
 *  Created on: 15/04/2015
 *      Author: raul
 */

#include "AVLNode.h"

template<typename T>
AVLNode<T>::AVLNode(T value) : INode<T>::INode(value)
{
	this->balanco = 0;
}

template <typename T>
AVLNode<T>::~AVLNode(){
	delete this->left;
	delete this->right;
}

template class AVLNode<double>;
