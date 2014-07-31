#include "iostream"

using namespace::std;

class Node {
public:
	Node(int value){
		this->value = value;
		this->leftChild = NULL;
		this->rightChild = NULL;
	};
	Node *getLeftChild(){return this->leftChild;}
	Node *getRightChild(){return this->rightChild;}
	void setLeftChild(Node *node){this->leftChild = node;}
	void setRightChild(Node *node){this->rightChild = node;}

	int getValue(){return this->value;}

private:
	int value;
	Node *leftChild;
	Node *rightChild;
};

class Heap {
public:
	Heap(){
		this->head = NULL;
	};
	~Heap();

	Node *getMax(){return this->head;}
	void insert(int value){
		Node *node = new Node(value);
		if (!this->head) {
			this->head = node;
		} else {
			insertHelper(this->head, node);
		}
	}
	void printInOrder(){
		if (!this->head) {
			cout << "Heap is empty." << endl;
		} else {
			cout << "Heap: ";
			printHelper(this->head);
			cout << endl;
		}
	}

private:
	Node *head;

	void printHelper(Node *node){
		// Left
		if (node->getLeftChild()) {
			printHelper(node->getLeftChild());
		}
		// Center
		cout << node->getValue() << " ";
		// Right
		if (node->getRightChild()) {
			printHelper(node->getRightChild());
		}
		return;
	}

	void insertHelper(Node *currentNode, Node *nodeToInsert){
		if (nodeToInsert->getValue() >= currentNode->getValue()) {
			if (!currentNode->getRightChild()) {
				currentNode->setRightChild(nodeToInsert);
				return;
			} else {
				insertHelper(currentNode->getRightChild(), nodeToInsert);
			}
		} else {
			// nodeToInsert->getValue() is less than or equal to currentNode->getValue()
			if (!currentNode->getLeftChild()) {
				currentNode->setLeftChild(nodeToInsert);
				return;
			} else {
				insertHelper(currentNode->getLeftChild(), nodeToInsert);
			}
		}
	}
};

int main(int argc, char const *argv[]) {

	Heap *heap = new Heap();

	heap->insert(5);
	heap->insert(7);
	heap->insert(1);
	heap->insert(2);
	heap->insert(8);
	heap->insert(4);

	heap->printInOrder();

	return 0;
}