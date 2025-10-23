#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    struct node *left;
    int data;
    struct node *right;
};

typedef struct node NODE;
NODE *root = NULL;

// Function declarations
void create(int);
void insert(NODE*, NODE*);

int search(NODE*, int);
void inordertraverse(NODE*);
void preordertraverse(NODE*);
void postordertraverse(NODE*);
NODE* find_max(NODE*);

// Function to create and insert a new node
void create(int value) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    newnode->data = value;
    newnode->left = newnode->right = NULL;

    if (root == NULL)
        root = newnode; // First node becomes root
    else
        insert(root, newnode); // Insert elsewhere
}

// Recursive insertion
void insert(NODE *root, NODE *newnode) {
    if (newnode->data < root->data) {
        if (root->left == NULL)
            root->left = newnode;
        else
            insert(root->left, newnode);
    } else {
        if (root->right == NULL)
            root->right = newnode;
        else
            insert(root->right, newnode);
    }
}

// Search for a value in the BST
int search(NODE* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find the maximum value node (used in deletion)
NODE* find_max(NODE* root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}
// In-order traversal of the BST
void inordertraverse(NODE *root) {
    if (root != NULL) {
        inordertraverse(root->left);
        printf("%d\t", root->data);
        inordertraverse(root->right);
    }
}
//pre-order traversal of the BST
void preordertraverse(NODE *root) {
    if (root != NULL) {
    	printf("%d\t", root->data);
        preordertraverse(root->left);
        preordertraverse(root->right);
    }
}
//post-order traversal of the BST
void postordertraverse(NODE *root) {
    if (root != NULL) {
        postordertraverse(root->left);
        postordertraverse(root->right);
         printf("%d\t", root->data);
    }
}

// Main menu
int main() {
    int ch, value;
    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Traverse (In-Order)\n3. Traverse (Pre-Order)\n4. Traverse (Post-Order)\n5. Search\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                create(value);
                break;
            case 2:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("In-Order Traversal: ");
                    inordertraverse(root);
                    printf("\n");
                }
                break;
                 case 3:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("Pre-Order Traversal: ");
                    preordertraverse(root);
                    printf("\n");
                }
                break;
                 case 4:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("Post-Order Traversal: ");
                    postordertraverse(root);
                    printf("\n");
                }
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Value %d found in the tree.\n", value);
                else
                    printf("Value %d not found in the tree.\n", value);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);
    return 0;
}
