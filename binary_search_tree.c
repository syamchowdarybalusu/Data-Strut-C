#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Find minimum value node
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search a node
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Leaf nodes
void printLeafNodes(struct Node* root) {
    if (!root) return;
    if (!root->left && !root->right)
        printf("%d ", root->data);
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// Internal nodes
void printInternalNodes(struct Node* root) {
    if (!root) return;
    if (root->left || root->right)
        printf("%d ", root->data);
    printInternalNodes(root->left);
    printInternalNodes(root->right);
}

// Find parent
void findParent(struct Node* root, int val, struct Node* parent) {
    if (!root) return;
    if (root->data == val) {
        if (parent)
            printf("Parent of %d is %d\n", val, parent->data);
        else
            printf("%d is the root node\n", val);
        return;
    }
    findParent(root->left, val, root);
    findParent(root->right, val, root);
}

// Find siblings
void findSiblings(struct Node* root, int val) {
    if (!root) return;
    if (root->left && root->right) {
        if (root->left->data == val)
            printf("Sibling of %d is %d\n", val, root->right->data);
        else if (root->right->data == val)
            printf("Sibling of %d is %d\n", val, root->left->data);
    }
    findSiblings(root->left, val);
    findSiblings(root->right, val);
}

// Ancestors
int printAncestors(struct Node* root, int val) {
    if (!root) return 0;
    if (root->data == val) return 1;

    if (printAncestors(root->left, val) || printAncestors(root->right, val)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

// Descendants
void printDescendants(struct Node* root) {
    if (!root) return;
    if (root->left)
        printf("%d ", root->left->data);
    if (root->right)
        printf("%d ", root->right->data);
    printDescendants(root->left);
    printDescendants(root->right);
}

// Main
int main() {
    struct Node* root = NULL;
    int choice, value;

    printf("Enter number of nodes to insert: ");
    int n;
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\nLeaf Nodes: ");
    printLeafNodes(root);

    printf("\nInternal Nodes: ");
    printInternalNodes(root);

    printf("\n\nEnter value to search: ");
    scanf("%d", &value);
    struct Node* found = search(root, value);
    if (found)
        printf("Value %d found\n", value);
    else
        printf("Value %d not found\n", value);

    printf("\nEnter value to find its parent: ");
    scanf("%d", &value);
    findParent(root, value, NULL);

    printf("Enter value to find its sibling: ");
    scanf("%d", &value);
    findSiblings(root, value);

    printf("Enter value to print ancestors: ");
    scanf("%d", &value);
    printf("Ancestors of %d: ", value);
    printAncestors(root, value);
    printf("\n");

    printf("Enter value to print descendants: ");
    scanf("%d", &value);
    struct Node* node = search(root, value);
    printf("Descendants of %d: ", value);
    printDescendants(node);
    printf("\n");

    printf("Enter value to delete: ");
    scanf("%d", &value);
    root = deleteNode(root, value);

    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
