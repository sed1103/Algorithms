#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BTree {
    struct BTree *left;
    struct BTree *right;
    int data;
    char ss[100];
};

struct BTree* createNode(int data, char* ss) {
    struct BTree* newNode = (struct BTree*)malloc(sizeof(struct BTree));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    strcpy(newNode->ss, ss);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BTree* createTree() {
    int data;
    char ss[100];
    struct BTree *root = NULL;
    char c;
    do {
        printf("Enter the value: ");
        scanf("%d", &data);
        printf("Enter the string: ");
        scanf("%s", ss);
        if (root == NULL) {
            root = createNode(data, ss);
        } else {
            struct BTree *current = root;
            struct BTree *parent;
            while (1) {
                parent = current;
                if (data < current->data) {
                    current = current->left;
                    if (current == NULL) {
                        parent->left = createNode(data, ss);
                        break;
                    }
                } else {
                    current = current->right;
                    if (current == NULL) {
                        parent->right = createNode(data, ss);
                        break;
                    }
                }
            }
        }
        printf("Do you want to continue (y/n): ");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
    return root;
}

void inorder(struct BTree *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("[%d, %s] ", root->data, root->ss);
        inorder(root->right);
    }
}

void preorder(struct BTree *root) {
    if (root != NULL) {
        printf("[%d, %s] ", root->data, root->ss);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct BTree *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("[%d, %s] ", root->data, root->ss);
    }
}

void levelOrder(struct BTree *root) {
    if (root == NULL) return;
    struct BTree *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct BTree *current = queue[front++];
        printf("[%d, %s] ", current->data, current->ss);
        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
}

int height(struct BTree* root) {
    if (root == NULL) return 0;
    else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight > rightHeight) return (leftHeight + 1);
        else return (rightHeight + 1);
    }
}

void printCurrentLevel(struct BTree* root, int level) {
    if (root == NULL) return;
    if (level == 1) printf("[%d, %s] ", root->data, root->ss);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void deleteTree(struct BTree* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    printf("\nFree: [%d, %s]", root->data, root->ss);
    free(root);
}

int main() {
    struct BTree *root = createTree();

    printf("\nInorder is: ");
    inorder(root);

    printf("\nPreorder is: ");
    preorder(root);

    printf("\nPostorder is: ");
    postorder(root);

    printf("\nBFS levelorder is: ");
    levelOrder(root);

    int h = height(root);
    printf("\nHeight of Tree: %d", h);

    printf("\nPrint value of level:\n");
    for (int i = 1; i <= h; i++) {
        printf("\tLevel-%d: ", i);
        printCurrentLevel(root, i);
        printf("\n");
    }

    deleteTree(root);

    return 0;
}
