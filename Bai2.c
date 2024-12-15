#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* firstChild; 
    struct Node* nextSibling; 
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void addChild(Node* parent, int childData) {
    Node* child = createNode(childData);
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

void findLevel2Nodes(Node* root) {
    if (root == NULL || root->firstChild == NULL) {
        printf("Khong co dinh nao o lop 2.\n");
        return;
    }

    Node* level1Node = root->firstChild;
    printf("Cac dinh o lop 2 la: ");

    while (level1Node != NULL) {
        Node* level2Node = level1Node->firstChild;
        while (level2Node != NULL) {
            printf("%d ", level2Node->data);
            level2Node = level2Node->nextSibling;
        }
        level1Node = level1Node->nextSibling;
    }

    printf("\n");
}

void printTree(Node* root, int level) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%d\n", root->data);

    Node* child = root->firstChild;
    while (child != NULL) {
        printTree(child, level + 1);
        child = child->nextSibling;
    }
}

int main() {
    Node* root = createNode(1); 

    addChild(root, 2);
    addChild(root, 3);
    addChild(root, 4);

    addChild(root->firstChild, 5); 
    addChild(root->firstChild, 6);

    addChild(root->firstChild->nextSibling, 7); 

    addChild(root->firstChild->nextSibling->nextSibling, 8); 

    printf("Cay da duoc xay dung:\n");
    printTree(root, 0);

    findLevel2Nodes(root);

    return 0;
}

