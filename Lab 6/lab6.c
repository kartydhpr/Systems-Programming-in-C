/*
	Description: Lab 06
    This lab utilizes dynamic linked lists to build a tree data structure
    to efficiently store data. This program, specifically, uses a Binary Search Tree
    data structure and performs numerous algorithms and functions on it.
	Due Date: April 24th, 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global variables

// tree node
struct Node{
    int value;
    struct Node* left;
    struct Node* right;
};

// create an empty binary tree with just a root pointer
struct Node* createTree0(){
    return NULL;
}

// create a binary tree with 1 root node, given the int parameter
struct Node* createTree1(int val){
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->value = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

// add a node to the tree, in the correct, ordered position, given the Node parameter
void addNode(struct Node* root, struct Node* newNode){
    if (root == NULL) {
        root = newNode;
        return;
    }

    if (newNode->value < root->value) {
        if (root->left == NULL) {
            root->left = newNode;
        } else {
            addNode(root->left, newNode);
        }
    } else {
        if (root->right == NULL) {
            root->right = newNode;
        } else {
            addNode(root->right, newNode);
        }
    }
}

// add a node to the tree, in the correct, ordered position, given the int value parameter
void addNodeMenu(struct Node* root, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    addNode(root, newNode);
}

// delete a node from the tree and maintain the correct order of the tree.
struct Node* deleteNode(struct Node* root, int value) {
    // If the root is NULL, the node to be deleted was not found, so return NULL.
    if (root == NULL) {
        return root;
    }
    // If the value to be deleted is less than the value of the root, recursively call deleteNode on the left subtree of the root.
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    }
        // If the value to be deleted is greater than the value of the root, recursively call deleteNode on the right subtree of the root.
    else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    }
        // If the value to be deleted is equal to the value of the root, we have found the node to be deleted.
    else {
        // If the root has no left child, replace the root with its right child (which may be NULL), free the root, and return the right child.
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
            // If the root has no right child, replace the root with its left child, free the root, and return the left child.
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // If the root has two children, find the node with the minimum value in the right subtree, replace the value of the root with the value of that node, and then recursively call deleteNode on the right subtree to delete that node.
        struct Node* current = root->right;
        while (current->left != NULL) {
            current = current->left;
        }
        root->value = current->value;
        root->right = deleteNode(root->right, current->value);
    }
    // Return the updated root pointer.
    return root;
}

// Search the binary tree for the value passed as a parameter. Return true if found and false if not found in the tree.
int traverseFind(struct Node* root, int value) {
    // If the root is NULL, the value was not found in the tree, so return false.
    if (root == NULL) {
        return 0; // false
    }
    // If the value to be found is less than the value of the root, recursively call traverseFind on the left subtree of the root.
    if (value < root->value) {
        return traverseFind(root->left, value);
    }
        // If the value to be found is greater than the value of the root, recursively call traverseFind on the right subtree of the root.
    else if (value > root->value) {
        return traverseFind(root->right, value);
    }
        // If the value to be found is equal to the value of the root, we have found the node with the value we were looking for, so return true.
    else {
        return 1; // true
    }
}

// Print out all the values in the tree in correct order (inorder traversal)
void traverseInOrderPrint(struct Node* root) {
    if (root != NULL) {
        traverseInOrderPrint(root->left);
        printf("%d ", root->value);
        traverseInOrderPrint(root->right);
    }
}

// Print out all the values in the tree in correct order (preorder traversal)
void traversePreOrderPrint(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        traversePreOrderPrint(root->left);
        traversePreOrderPrint(root->right);
    }
}

// Print out all the values in the tree in correct order (postorder traversal)
void traversePostOrderPrint(struct Node* root) {
    if (root != NULL) {
        traversePostOrderPrint(root->left);
        traversePostOrderPrint(root->right);
        printf("%d ", root->value);
    }
}

// mainline logic
int main()
{
    printf("Program Starting...\n");

    char fileLine[100];
    char fileCommand[20];
    int value;


    int runProgram = 1; // 0 is false 1 is true
	while(runProgram == 1)
	{

        struct Node *root; // init root node of BST
        createTree0(&root); // create tree with root being null

        // implementation of file I/O
        FILE *inFile;
        inFile = fopen("testing.txt", "r"); // open the file for reading
        if(inFile == NULL){
            printf("The file could not be opened...\nPlease make sure the file currently exists\n");
            exit(1);
        }
        printf("File opened succesfully!\n");

        // implement read logic here
        while(fgets(fileLine, sizeof(fileLine), inFile) != NULL){
            scanf(fileLine, "%s" "%d", fileCommand, &value);

        }


		printf("Do you want to run the program again? (y/n): ");
		char decision;
		scanf(" %c", &decision);

		if (decision == 'y')
		{
			runProgram = 1;
		}
		else
		{
			runProgram = 0;
			printf("[5] Program terminating...\n");
		}
	}
}
