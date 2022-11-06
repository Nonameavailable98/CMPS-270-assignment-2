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
    bool DeleteNode(T val);
    int SubtreeSize(struct treeNode * treeNode);
    //I couldn't implement the tree as a complete tree so i implemented it as a binary search tree
    void add(T val);

    private:
	struct treeNode* root;
	int treeSize;
    void add(struct treeNode** treeNode, T val);
    void printPreOrder(struct treeNode* treeNode);
    void printInOrder(struct treeNode* treeNode);
    void printPostOrder(struct treeNode* treeNode);
    bool DeleteNode(struct treeNode* treeNode, T val);
    void deleteTree(struct treeNode* treeNode);
    

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
// requires:
// nothing
// effects:
// adds node with given key to the tree
template <class T>
void BinaryTree<T>::add(T val){
	add(&(this->root), val);
}
//Helper Function
template <class T>
void BinaryTree<T>::add(struct treeNode** treeNode, T val){

	if(*treeNode == NULL)	{
		struct treeNode* tmp = new struct treeNode;
		tmp->data = val;
		tmp->left=NULL;
		tmp->right = NULL;
		*treeNode = tmp;

		this->treeSize++;
	}else{
		if(val > (*treeNode)->data){
			add(&(*treeNode)->right, val);
		}else{
			add(&(*treeNode)->left, val);
		}
	}
}
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
// requires:
// node with given value to exist 
// effect:
// deletes the node holding given value
template <class T>
bool BinaryTree<T>::DeleteNode(T val){
	return DeleteNode(this->root, val);
}
//Helper Function
template <class T>
bool BinaryTree<T>::DeleteNode(struct treeNode* treeNode, T val){
	if(treeNode == NULL){
		return false;
	}else{
		if(val == treeNode->data){
            std::cout<<"Cannot Delete Node"<<std::endl;
			return true;
		}

		if(val > treeNode->data){
            if(treeNode->right->data == treeNode->data)
            treeNode->right= nullptr;

			return DeleteNode(treeNode->right, val);
		}else{
            if(treeNode->left->data == treeNode->data)
            treeNode->left= nullptr;
			return DeleteNode(treeNode->left, val);
		}
	}
}
// requires:
// nothing
// effects:
// returns size of subtree starting from given node
template <class T>
int BinaryTree<T>::SubtreeSize(struct treeNode* treeNode)
{
       if(treeNode == nullptr)
    return 0;
    else 
    return 1 + SubtreeSize(treeNode->left) + SubtreeSize(treeNode->right);
}

template <class T>
void BinaryTree<T>::deleteTree(struct treeNode* treeNode){
	if(treeNode != NULL){
		deleteTree(treeNode->left);
		deleteTree(treeNode->right);
		delete treeNode;
	}
}

int main(){

    BinaryTree<int> tree;

	tree.add(5);
	tree.add(4);
	tree.add(7);
	tree.add(10);
	tree.add(1);
	tree.add(2);

	tree.printPostOrder();
	tree.printInOrder();
	tree.printPreOrder();

	std::cout << "Tree size: " << tree.size() << std::endl;

	BinaryTree<char> tee;

	tee.add('z');
	tee.add('0');
	tee.add('9');
	tee.add('a');
	tee.add('A');
	tee.add('Z');

	std::cout << "Contains 9? : "<< ((tee.DeleteNode('9'))? "true" : "false" ) << std::endl;

	tee.printPostOrder();
	tee.printInOrder();
	tee.printPreOrder();

	std::cout << "Tree size: " << tee.size() << std::endl;
    return 0;
}