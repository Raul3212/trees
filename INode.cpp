/*
 * INode.cpp
 *
 *  Created on: 10/05/2015
 *      Author: raul
 */

#include "INode.h"

template <typename T>
INode<T>::INode(T value){
	this->value = value;
}

template <typename T>
INode<T>::~INode() {
	delete this->left;
	delete this->right;
}

template class INode<double>;
