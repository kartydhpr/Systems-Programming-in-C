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
void deleteNode(int){ // param is the value of node to delete

}

// Search the binary tree for the value passsed as a paramter. Return true if found and false if not found in the tree
void traverseFind(int){

}

// Print out all the values in the tree in correct order
void traverseInOrderPrint(){ // root will be visited in the middle. First left, then root, then right.

}

// Print out all the values in the tree in correct order
void traversePreOrderPrint(){ // root will be visited first

}

void traversePostOrderPrint(){ // visit root at the end

}

// mainline logic
int main()
{
    printf("Program Starting...\n");

    int runProgram = 1; // 0 is false 1 is true
	while(runProgram == 1)
	{
        // implementation of file I/O
        FILE *inFile;
        inFile = fopen("testing.txt", "r"); // open the file for reading
        if(inFile == NULL){
            printf("The file could not be opened...\nPlease make sure the file currently exists\n");
            exit(1);
        }
        printf("File opened succesfully!\n");

        // implement read logic here - appending lines to array for BST moves

		printf("Do you want to perform more operations? (y/n): ");
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
