#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Dinh nghia cau truc cua mot nut trong cay nhi phan
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Ham tao mot nut moi
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Ham them mot dinh vao cay
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Ham kiem tra tinh chat cay BST bang de quy
bool isBSTUtil(Node* root, Node* minNode, Node* maxNode) {
    if (root == NULL) {
        return true;
    }

    if ((minNode != NULL && root->data <= minNode->data) ||
        (maxNode != NULL && root->data >= maxNode->data)) {
        return false;
    }

    return isBSTUtil(root->left, minNode, root) &&
           isBSTUtil(root->right, root, maxNode);
}

bool isBST(Node* root) {
    return isBSTUtil(root, NULL, NULL);
}

// Duyet cay theo thu tu truoc (preorder traversal)
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    Node* tree = NULL;

    // Them cac dinh vao cay
    tree = insertNode(tree, 10);
    tree = insertNode(tree, 5);
    tree = insertNode(tree, 20);
    tree = insertNode(tree, 3);
    tree = insertNode(tree, 7);
    tree = insertNode(tree, 15);
    tree = insertNode(tree, 25);

    // Hien thi cay theo thu tu truoc
    printf("Cay nhi phan (duyet truoc): ");
    preorderTraversal(tree);
    printf("\n");

    // Kiem tra tinh chat cay BST
    if (isBST(tree)) {
        printf("Cay la mot cay nhi phan tim kiem (BST).\n");
    } else {
        printf("Cay khong phai la cay nhi phan tim kiem (BST).\n");
    }

    return 0;
}

