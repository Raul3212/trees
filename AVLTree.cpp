/*
 * AVLTree.cpp
 *
 *  Created on: 15/04/2015
 *      Author: raul
 */

#include "AVLTree.h"

template <typename T>
AVLTree<T>::AVLTree(){
	this->raiz = NULL;
}


template<typename T>
inline AVLTree<T>::AVLTree(list<T> values) {
	for(T v : values){
		this->insert(v);
	}
}

template <typename T>
AVLTree<T>::~AVLTree(){
	for(AVLNode<T>* i : this->getAllNodeReferences((AVLNode<T>*)this->raiz)){
		delete i;
	}
}


template<typename T>
inline bool AVLTree<T>::insert(T value) {

	stack<AVLNode<T>*> stack;
	AVLNode<T>* no = new AVLNode<T>(value);

	if(this->raiz == NULL){
		this->raiz = no;
		return true;
	}

	else{
		AVLNode<T>* r = (AVLNode<T>*)this->raiz;

		while(r != NULL){
			stack.push(r);
			if(r->value == value)
				return false;

			else if(value < r->value)
				r = (AVLNode<T>*)r->left;

			else r = (AVLNode<T>*)r->right;

		}
		AVLNode<T>* pai = stack.top();
		if(value < pai->value)
			pai->left = no;
		else pai->right = no;

		while(!stack.empty()){
			AVLNode<T>* x = stack.top();
			stack.pop();

			if(value < x->value)
				x->balanco--;
			else x->balanco++;

			if(x->balanco == 0)
				return true;
			else if(abs(x->balanco) == 2){
				AVLNode<T>* z;
				if(x->balanco == -2 and ((AVLNode<T>*)x->left)->balanco == -1)
					z = simpleRightRotation(x);
				else if(x->balanco == -2 and ((AVLNode<T>*)x->left)->balanco == 1)
					z = doubleRightRotation(x);
				else if(x->balanco == 2 and ((AVLNode<T>*)x->right)->balanco == 1)
					z = simpleLeftRotation(x);
				else z = doubleLeftRotation(x);

				if(this->raiz == x)
					this->raiz = z;

				else{
					pai = stack.top();
					stack.pop();

					if(pai->right == x)
						pai->right = z;

					else pai->left = z;
				}
				return true;
			}
		}
	}
	return true;

}

template<typename T>
inline bool AVLTree<T>::remove(T value) {
	return false;
}

template<typename T>
inline AVLNode<T>* AVLTree<T>::simpleLeftRotation(AVLNode<T>* node) {
	AVLNode<T>* y = (AVLNode<T>*)node->right;
	AVLNode<T>* t2 = (AVLNode<T>*)y->left;

	y->left = node;
	node->right = t2;

	node->balanco = 0;
	y->balanco = 0;

	return y;
}

template<typename T>
inline AVLNode<T>* AVLTree<T>::simpleRightRotation(AVLNode<T>* node) {
	AVLNode<T>* y = (AVLNode<T>*)node->left;
	AVLNode<T>* t2 = (AVLNode<T>*)y->right;

	y->right = node;
	node->left = t2;

	node->balanco = 0;
	y->balanco = 0;

	return y;
}

template<typename T>
inline AVLNode<T>* AVLTree<T>::doubleLeftRotation(AVLNode<T>* node) {
	AVLNode<T>* y = (AVLNode<T>*)node->right;
	AVLNode<T>* z = (AVLNode<T>*)y->left;

	y->left = z->right;
	z->right = y;
	node->right = z->left;
	z->left = node;

	if(z->balanco < 0){
		((AVLNode<T>*)z->left)->balanco = 0;
		((AVLNode<T>*)z->right)->balanco = 1;
	}
	else{
		((AVLNode<T>*)z->left)->balanco = -1;
		((AVLNode<T>*)z->right)->balanco = 0;
	}
	z->balanco = 0;

	return z;
}

template<typename T>
inline list<AVLNode<T> *> AVLTree<T>::getAllNodeReferences(AVLNode<T>* raiz) const {
	list<AVLNode<T>*> nodes;
	if(raiz != NULL){
		nodes.push_back(raiz);
		getAllNodeReferences((AVLNode<T>*)raiz->left);
		getAllNodeReferences((AVLNode<T>*)raiz->right);
	}
	return nodes;
}

template<typename T>
inline AVLNode<T>* AVLTree<T>::doubleRightRotation(AVLNode<T>* node) {
	AVLNode<T>* y = (AVLNode<T>*)node->left;
	AVLNode<T>* z = (AVLNode<T>*)y->right;

	y->right = z->left;
	z->left = y;
	node->left = z->right;
	z->right = node;

	if(z->balanco < 0){
		((AVLNode<T>*)z->left)->balanco = 0;
		((AVLNode<T>*)z->right)->balanco = 1;
	}
	else{
		((AVLNode<T>*)z->left)->balanco = -1;
		((AVLNode<T>*)z->right)->balanco = 0;
	}
	z->balanco = 0;

	return z;
}

template class AVLTree<double>;
