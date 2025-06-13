#include <stdio.h>
#include <stdlib.h>

// Node structure for BST using left and right pointers (like a doubly linked list node)
typedef struct Node {
    int data;
    struct Node* left;   // Acts like prev
    struct Node* right;  // Acts like next
} Node;

// Create a new BST node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node in BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// In-order traversal (sorted order)
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Search a value in BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Free the tree
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Driver code
int main() {
    Node* root = NULL;
    int n, val, key;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("In-order Traversal (sorted): ");
    inorder(root);
    printf("\n");

    printf("Enter value to search: ");
    scanf("%d", &key);
    Node* result = search(root, key);
    if (result)
        printf("Found %d in the tree.\n", result->data);
    else
        printf("Value not found.\n");

    freeTree(root);
    return 0;
}
