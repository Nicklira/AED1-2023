#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int search(struct Node* root, char data) {
    while (root != NULL) {
        if (data == root->data) {
            return 1;
        } else if (data < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return 0;
}

int main() {
    struct Node* root = NULL;
    char command[10];
    char data;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "I") == 0) {
            scanf(" %c", &data);
            root = insert(root, data);
        } else if (strcmp(command, "INFIXA") == 0) {
            inorder(root);
            printf("\n");
        } else if (strcmp(command, "PREFIXA") == 0) {
            preorder(root);
            printf("\n");
        } else if (strcmp(command, "POSFIXA") == 0) {
            postorder(root);
            printf("\n");
        } else if (strcmp(command, "P") == 0) {
            scanf(" %c", &data);
            int result = search(root, data);
            if (result) {
                printf("%c existe\n", data);
            } else {
                printf("%c nao existe\n", data);
            }
        }
    }

    return 0;
}
