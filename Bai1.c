#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
} Node;

Node* createNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

// Chen 1 nut vao cay
Node* insertNode(Node* node, int data){
	if(node == NULL){
	    return createNode(data);
	}
	if(data < node->data){
		node->left = insertNode(node->left, data);
	}else if(data > node->data){
		node->right = insertNode(node->right, data);
	}
	return node;
}

void preorderTraversal(Node* node){
	if(node != NULL){
		printf("%d\t", node->data);
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}
}

void inOrderTraversal(Node* node){
	if(node != NULL){
		inOrderTraversal(node->left);
		printf("%d\t", node->data);
		inOrderTraversal(node->right);
	}
}

void postOrderTraversal(Node* node){
	if(node != NULL){
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		printf("%d\t", node->data);
	}
}

int main(){
	Node* tree = NULL;
	
	// Chen
	tree = insertNode(tree, 4);
	tree = insertNode(tree, 3);
	tree = insertNode(tree, 6);
	tree = insertNode(tree, 2);
	tree = insertNode(tree, 5);
	
	preorderTraversal(tree);
	printf("\n");
	inOrderTraversal(tree);
	printf("\n");
	postOrderTraversal(tree);
	return 0;
}
