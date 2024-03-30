#include <stdio.h>
#include <stdlib.h>

struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* GetNewNode(int data) {
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

struct BstNode* FindMin(struct BstNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct BstNode* Delete(struct BstNode* root, int data) {
    if (root == NULL) return root;
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL) {
            struct BstNode* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct BstNode* temp = root;
            root = root->left;
            free(temp);
        }
        else {
            struct BstNode* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

struct BstNode* Search(struct BstNode* root, int data) {
    if (root == NULL || root->data == data) return root;
    else if (data < root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

int main() {
    struct BstNode* root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    int number;
    printf("Enter number to be searched: ");
    scanf("%d", &number);
    struct BstNode* found = Search(root, number);
    if (found != NULL) printf("Found\n");
    else printf("Not Found\n");

    printf("Enter number to be deleted: ");
    scanf("%d", &number);
    root = Delete(root, number);

    return 0;
}
