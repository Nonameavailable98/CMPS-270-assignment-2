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
    int size();
    void printPreOrder();
    void printInOrder();
    void printPostOrder();

    private:
	struct treeNode* root;
	int treeSize;
    void printPreOrder(struct treeNode* treeNode);
    void printInOrder(struct treeNode* treeNode);
    void printPostOrder(struct treeNode* treeNode);

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
// nothing
// effect:
// destructs calling object
template <class T>
BinaryTree<T>::~BinaryTree(){
	deleteTree(this->root);
}
// requires:
// nothing
// effects:
// returns tree size
template <class T>
int BinaryTree<T>::size(){
	return this->treeSize;
}
// requires:
// nothing
// effects:
// prints Given tree object using pre-order travresal
template <class T>
void BinaryTree<T>::printPreOrder(){
	printPreOrder(this->root);
	std::cout << std::endl;
}
//Hleper Function
template <class T>
void BinaryTree<T>::printPreOrder(struct treeNode* treeNode){
	if(treeNode != NULL)	{
		std::cout << treeNode->data << ", ";
		printInOrder(treeNode->left);
		printInOrder(treeNode->right);
	}
}
    // requires:
    // nothing
    // effect:
    // prints Given tree object using in-order travresal
    template <class T>
void BinaryTree<T>::printInOrder(){
	printInOrder(this->root);
	std::cout << std::endl;
}
//Helper Function
template <class T>
void BinaryTree<T>::printInOrder(struct treeNode* treeNode){
	if(treeNode != NULL){
		printInOrder(treeNode->left);
		std::cout << treeNode->data << ", ";
		printInOrder(treeNode->right);
	}
}
    // requires:
    // nothing
    // effect:
    // prints Given tree object using post-order travresal
template <class T>
void BinaryTree<T>::printPostOrder(){
	printPostOrder(this->root);
	std::cout << std::endl;
}
//Helper Function
template <class T>
void BinaryTree<T>::printPostOrder(struct treeNode* treeNode){
	if(treeNode != NULL){
		printInOrder(treeNode->left);
		printInOrder(treeNode->right);
		std::cout << treeNode->data << ", ";
	}
}

int main(){
    return 0;
}