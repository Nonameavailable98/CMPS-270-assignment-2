#include <iostream>
#include <queue>
#define SIZE 50

template <class T>
class BinaryTree
{

	struct treeNode{
		T data;
		struct treeNode* right = nullptr;
		struct treeNode* left = nullptr;
	};

    public:
	BinaryTree();
	~BinaryTree();

    private:
	struct treeNode* root;
	int treeSize;

};

// requires:
// nothing
// effect:
// contruct a new BinaryTree Object



template <class T>
BinaryTree<T>::BinaryTree(){
	this->root = NULL;
	this->treeSize = 0;
}

// requires:
// existence of BinaryTree object
// effect:
// destructs calling object
template <class T>
BinaryTree<T>::~BinaryTree(){
	deleteTree(this->root);
}

int main(){
    return 0;
}