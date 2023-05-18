#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a binary tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to construct the binary tree and compute post-order traversal
struct Node* constructTree(char* inOrder, char* preOrder, int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    // Find the current root node in the in-order traversal
    struct Node* root = createNode(preOrder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd)
        return root;

    // Find the index of the current root node in the in-order traversal
    int inIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inOrder[i] == root->data) {
            inIndex = i;
            break;
        }
    }

    // Construct the left and right subtrees recursively
    root->left = constructTree(inOrder, preOrder, inStart, inIndex - 1, preIndex);
    root->right = constructTree(inOrder, preOrder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Function to compute post-order traversal
void postOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%c", root->data);
}

int main() {
    int C;
    scanf("%d", &C);

    for (int i = 0; i < C; i++) {
        int N;
        scanf("%d", &N);

        char S1[53];
        char S2[53];
        scanf("%s%s", S1, S2);

        int preIndex = 0;
        struct Node* root = constructTree(S2, S1, 0, N - 1, &preIndex);

        postOrderTraversal(root);
        printf("\n");

        // Free memory
        // ...
    }

    return 0;
}
