/*
 * INode.h
 *
 *  Created on: 10/05/2015
 *      Author: raul
 */

#ifndef INODE_H_
#define INODE_H_

#include <iostream>

using namespace std;

template <typename T>
class INode {

public:
	T value;
	INode<T>* left{NULL};
	INode<T>* right{NULL};

	INode(T value);
	~INode();
};

#endif /* INODE_H_ */
