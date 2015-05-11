#ifndef NODEDE_H_
#define NODEDE_H_

#include "INode.h"
#include <iostream>

using namespace std;

template <typename T>
class AVLNode : public INode<T>
{
public:
	int balanco;
	AVLNode(T value);
	virtual ~AVLNode();
};

#endif /* NODEDE_H_ */
