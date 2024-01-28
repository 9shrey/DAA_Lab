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
    if (root == NULL || root->data == key){
        return root;
    }

    if (root->data < key){
        return search(root->right, key);
    }

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
    int key;
    struct Node* root = createNode(2);
    struct Node* temp = createNode(1);
    insert(root, temp);
    temp = createNode(3);
    insert(root, temp);
    insert(root, createNode(5));

    do{
		printf("Enter key to search and -1 to exit: ");
		scanf("%d",&key);
		if(key==-1){
			break;
		}
		temp = search(root,key);
		if(temp != NULL){
			printf("Key Found\n");
		}
		if(temp == NULL){
			printf("Inserting Key\n");
			insert(root, createNode(key));
		}
	}while(key!=-1);

    printf("Root: %d\n", root->data);
    printf("Left Child: %d\n", root->left->data);
    printf("Right Child: %d\n", root->right->data);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}