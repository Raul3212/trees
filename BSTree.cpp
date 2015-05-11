#include "BSTree.h"

template <typename T>
BSTree<T>::BSTree(){
    this->raiz = NULL;
}


template<typename T>
inline BSTree<T>::BSTree(list<T> values){
	for(T v : values){
		this->insert(v);
	}
}

template<typename T>
inline BSTree<T>::~BSTree(){
	for(Node<T>* i : this->getAllNodeReferences((Node<T>*)this->raiz)){
		delete i;
	}
//	delete (Node<T>*)this->raiz;
}

template <typename T>
bool BSTree<T>::insert(T value)
{
    if(this->raiz == NULL){
        this->raiz = new Node<T>(value);
    }
    else{
        Node<T>* no = (Node<T>*)this->raiz;
        Node<T>* pai = NULL;

        while(no != NULL){
            if(no->value == value)
                return false;
            else if (no->value < value){
                pai = no;
                no = (Node<T>*)no->right;
            }
            else{
                pai = no;
                no = (Node<T>*)no->left;
            }
        }
        if(pai->value < value){
            pai->right = new Node<T>(value);
        }
        else{
            pai->left = new Node<T>(value);
        }
    }
    return true;
}

template <typename T>
bool BSTree<T>::remove(T value)
{
    Node<T>* pai = NULL;
    Node<T>* no_i = (Node<T>*)this->raiz;
    Node<T>* sucessor = NULL;

    while(no_i != NULL){
        if(no_i->value == value){
            break;
        }
        else if(value < no_i->value){
            pai = no_i;
            no_i = (Node<T>*)no_i->left;
        }
        else{
            pai = no_i;
            no_i = (Node<T>*)no_i->right;
        }
    }

    if(no_i == NULL) return false; //O nó não está na árvore

    else{
        if(no_i->left != NULL && no_i->right != NULL){
            sucessor = (Node<T>*)getSucessor(no_i);
            pai = no_i;
            no_i->value = sucessor->value;
            no_i = sucessor;

        }

        if(no_i->left == NULL){
            if(pai == NULL){
                this->raiz = no_i->right;
            }
            else{
                if(pai->left == no_i){
                    pai->left = no_i->right;
                }
                else{
                    pai->right = no_i->right;
                }
            }
        }
        else if(no_i->right == NULL){
            if(pai == NULL){
                this->raiz = no_i->left;
            }
            else{
                if(pai->left == no_i){
                    pai->left = no_i->left;
                }
                else{
                    pai->right = no_i->left;
                }
            }
        }

        delete no_i;
        return true;
    }

}

template <typename T>
bool BSTree<T>::contains(T value) const
{
    Node<T>* no = (Node<T>*)this->raiz;
    while(no != NULL){
        if(no->value == value)
            return true;
        else if (no->value < value)
            no = (Node<T>*)no->left;
        else
            no = (Node<T>*)no->right;

    }
    return false;
}


template<typename T>
inline unsigned int BSTree<T>::getAlura()
{
	return getAltura(this->raiz);
}

template<typename T>
inline unsigned int BSTree<T>::getAlura(T value)
{
	return getAltura(search(value));
}

template<typename T>
inline unsigned int BSTree<T>::getNivel(T value)
{
	return getNivel(search(value));
}

template <typename T>
T BSTree<T>::getMenor() const
{
    return getMenor(this->raiz)->value;
}

template <typename T>
T BSTree<T>::getMaior() const
{
    return getMaior(this->raiz)->value;
}


template <typename T>
unsigned int BSTree<T>::getAltura(const INode<T>* node)
{
    if(node != NULL){
        return 1+max(getAltura(node->left), getAltura(node->right));
    }
    else{
        return 0;
    }
}

template <typename T>
INode<T>* BSTree<T>::getMenor(INode<T>* raiz) const
{
    if(&raiz == NULL) return NULL;

    Node<T>* menor = (Node<T>*)raiz;
    while(menor->left != NULL){
        menor = (Node<T>*)menor->left;
    }
    return menor;
}

template <typename T>
INode<T>* BSTree<T>::getMaior(INode<T> *raiz) const
{
    if(&raiz == NULL) return NULL;

    Node<T>* maior = (Node<T>*)raiz;
    while(maior->right != NULL){
        maior = (Node<T>*)maior->right;
    }
    return maior;
}

template<typename T>
INode<T>* BSTree<T>::getSucessor(const INode<T>* raiz) const
{
	if(raiz == NULL) return NULL;
	return getMenor(raiz->right);
}

template<typename T>
INode<T>* BSTree<T>::getAntecessor(const INode<T>* raiz) const
{
	if(raiz == NULL) return NULL;
	return getMaior(raiz->left);
}

template <typename T>
unsigned int BSTree<T>::getNivel(const INode<T>* node)
{
    Node<T>* no_i = (Node<T>*)this->raiz;
    int nivel = 0;

    while(no_i != NULL){
        if(no_i->value == node->value){
            return nivel;
        }
        else if(no_i->value > node->value){
            no_i = (Node<T>*)no_i->left;
            nivel++;
        }
        else{
            no_i = (Node<T>*)node->right;
            nivel++;
        }
    }
}

template <typename T>
INode<T>* BSTree<T>::search(T value)
{
	INode<T>* no = this->raiz;
    while(no != NULL){
        if(no->value == value)
            return no;
        else if (no->value < value)
            no = no->left;
        else
            no = no->right;

    }
    return NULL;
}


template<typename T>
inline list<Node<T> *> BSTree<T>::getAllNodeReferences(Node<T>* raiz) const {
	list<Node<T>*> nodes;
	if(raiz != NULL){
		nodes.push_back(raiz);
		getAllNodeReferences((Node<T>*)raiz->left);
		getAllNodeReferences((Node<T>*)raiz->right);
	}
	return nodes;
}


template class BSTree<double>;
//template class BSTree<int>;
//template class BSTree<string>;
