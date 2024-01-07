#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node *root, Node *temp){
    if(temp->data < root->data){
        if(root->left!=NULL){
            insert(root->left, temp);
        }
        else{
            root->left = temp;
        }
    }
    if(temp->data > root->data){
        if(root->right!=NULL){
            insert(root->right,temp);
        }
        else{
            root->right = temp;
        }
    }
    
}

struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Create the root node
    struct Node* root = createNode(2);
    struct Node* temp = createNode(1);
    // Create the left and right child nodes
    insert(root, temp);
    temp = createNode(3);
    insert(root, temp);
    insert(root, createNode(5));


    // Print the data of the root node and its children
    printf("Root: %d\n", root->data);
    printf("Left Child: %d\n", root->left->data);
    printf("Right Child: %d\n", root->right->data);

    // Perform inorder traversal
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    // Perform preorder traversal
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    // Perform postorder traversal
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
