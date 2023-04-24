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

void addNode(struct Node** rootPtr, struct Node* newNode){
    if (*rootPtr == NULL) {
        *rootPtr = newNode;
        return;
    }

    if (newNode->value < (*rootPtr)->value) {
        if ((*rootPtr)->left == NULL) {
            (*rootPtr)->left = newNode;
        } else {
            addNode(&((*rootPtr)->left), newNode);
        }
    } else {
        if ((*rootPtr)->right == NULL) {
            (*rootPtr)->right = newNode;
        } else {
            addNode(&((*rootPtr)->right), newNode);
        }
    }
}

void addNodeMenu(struct Node** rootPtr, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    addNode(rootPtr, newNode);
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

        addNodeMenu(&root, 45);
        addNodeMenu(&root, 25);
        addNodeMenu(&root, 65);
        addNodeMenu(&root, 15);
        printf("\nIn order print: ");
        traverseInOrderPrint(root);
        printf("\nPre order print: ");
        traversePreOrderPrint(root);
        printf("\nPost order print: ");
        traversePostOrderPrint(root);
        printf("\n\n\n");

        // implement read logic here
        while(fgets(fileLine, sizeof(fileLine), inFile) != NULL){
            sscanf(fileLine, "%s" "%d", fileCommand, &value);
            // logic for insert
            if (strcmp(fileCommand, "insert") == 0){
                if(root == NULL) { // if it's the first insert command create a tree with the passed value
                    createTree1(value);
                }
                else{
                    if(traverseFind (root, value) == 1) // if the value is already inside the tree
                        printf("This integer has already been added to the tree...\n");
                    else
                        addNodeMenu(&root, value);
                }
            }
            // logic for delete
            else if(strcmp(fileCommand, "delete") == 0){
                if(root == NULL){
                    printf("The tree is empty. Nothing to delete!\n");
                }
                else{
                    if(traverseFind(root, value) == 0){
                        printf("\nThis value does not exist in the tree...\n");
                    }
                    else{
                        deleteNode(root, value);
                    }
                }
            }
            // logic for traversal
            else if(strcmp(fileCommand, "traverse") == 0){
                char orderBy[20];
                if(sscanf(fileLine, "%s %s", fileCommand, orderBy) != 2){
                    printf("Absent traversal order\n");
                    continue;
                }
                if(strcmp(orderBy, "pre-order") == 0){
                    printf("\nPre-order print: ");
                    traversePreOrderPrint(root);
                }
                else if(strcmp(orderBy, "in-order") == 0){
                    printf("\nIn-order print: ");
                    traverseInOrderPrint(root);
                }
                else if(strcmp(orderBy, "post-order") == 0){
                    printf("\nPost-order print: ");
                    traversePostOrderPrint(root);
                }
                else{
                    printf("Invalid traversal order...\n");
                }
;            }
        }

		printf("\nDo you want to run the program again? (y/n): ");
		char decision;
		scanf(" %c", &decision);

		if (decision == 'y')
		{
			runProgram = 1;
		}
		else
		{
			runProgram = 0;
			printf("\nProgram terminating...\n");
		}
	}
}
