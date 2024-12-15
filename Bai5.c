#include<stdio.h>
#include<stdlib.h>

// Dinh nghia 1 nut
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right; 
} Node;

// Tao ra 1 nut moi
Node* createNode(int data){
	// Cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	
	// Gan data;
	newNode->data = data;
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

void inOrderTraversal(Node* node){
	if(node != NULL){
		inOrderTraversal(node->left);
		printf("%d\t", node->data);
		inOrderTraversal(node->right);
	}
}

void searchNumber(Node* node, int n){
	if(node == NULL){
		printf("Gia tri %d khong ton tai trong cay", n);
		return;
	}
	if(node->data == n){
		printf("Gia tri %d ton tai trong cay", n);
		return;
	}
	if (n < node->data) {
        searchNumber(node->left, n);
    } else {
        searchNumber(node->right, n);
    }
}

int main(){
	Node* tree = NULL;
	int n;
	
	// Chen
	tree = insertNode(tree, 4);
	tree = insertNode(tree, 3);
	tree = insertNode(tree, 6);
	tree = insertNode(tree, 2);
	tree = insertNode(tree, 5);
	
	inOrderTraversal(tree);
	printf("\n");
	
	printf("Nhap gia tri n: ");
	scanf("%d", &n);
	
	searchNumber(tree, n);

	return 0;
}
