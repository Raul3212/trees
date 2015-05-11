#include "BinaryTree.h"

template <typename T>
BinaryTree<T>::BinaryTree()
{}

template<typename T>
inline BinaryTree<T>::~BinaryTree() {
	for(INode<T>* i : getAllNodeReferences(this->raiz)){
		delete i;
	}
}

template<typename T>
list<T> BinaryTree<T>::getPreOrder() const{
	return preOrder(this->raiz);
}


template<typename T>
inline list<T> BinaryTree<T>::getInOrder() const {
	return inOrder(this->raiz);
}

template<typename T>
list<T> BinaryTree<T>::getPosOrder() const{
	return posOrder(this->raiz);
}

template<typename T>
unsigned int BinaryTree<T>::countNodes(const INode<T>* raiz) const{
	if(raiz == NULL) return 0;
	return (1 + countNodes(raiz->left) + countNodes(raiz->right));
}

template<typename T>
unsigned int BinaryTree<T>::getQntNodes() const {
	return countNodes(this->raiz);
}

template<typename T>
list<T> BinaryTree<T>::inOrder(const INode<T>* raiz) const{
	static list<T> valores;
	if(raiz != NULL){
		inOrder(raiz->left);
		valores.push_back(raiz->value);
		inOrder(raiz->right);
	}
	return valores;
}

template<typename T>
inline list<T> BinaryTree<T>::preOrder(const INode<T>* raiz) const{
	static list<T> valores;
	if(raiz != NULL){
		valores.push_back(raiz->value);
		preOrder(raiz->left);
		preOrder(raiz->right);
	}
	return valores;
}

template<typename T>
inline list<T> BinaryTree<T>::posOrder(const INode<T>* raiz) const{
	static list<T> valores;
	if(raiz != NULL){
		posOrder(raiz->left);
		posOrder(raiz->right);
		valores.push_back(raiz->value);
	}
	return valores;
}

template<typename T>
inline void BinaryTree<T>::printInOrder(INode<T>* raiz) const {
	INode<T>* p[100];
	int t = 0;
	INode<T>* no = raiz;

	while(no != NULL || t > 0){

		if(no != NULL){
			p[t] = no;
			t++;
			no = no->left;
		}
		else{
			no = p[t-1];
			t--;
			cout << no->value << " ";
			no = no->right;
		}
	}

}

template<typename T>
inline void BinaryTree<T>::printInOrder() const {
	printInOrder(this->raiz);
}

template<typename T>
inline list<INode<T> *> BinaryTree<T>::getAllNodeReferences(INode<T>* raiz) const {
	list<INode<T>*> nodes;
	if(raiz != NULL){
		nodes.push_back(raiz);
		getAllNodeReferences(raiz->left);
		getAllNodeReferences(raiz->right);
	}
	return nodes;
}

template<typename T>
string BinaryTree<T>::vectorToString(list<T> v){
	stringstream ss;
	for(T &i : v){
		ss << i << " ";
	}
	return ss.str();
}

template class BinaryTree<double>;
//template class BinaryTree<int>;
//template class BinaryTree<string>;
