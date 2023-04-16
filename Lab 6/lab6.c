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
    struct Node *left;
    struct Node *right;
};

// create an empty binary tree with just a root pointer
void createTree0(){

}

// create a binary tree with 1 root node, given the int parameter
void createTree1(int){

}

// add a node to the tree, in the correct, ordered position, given the Node parameter
void addNode(struct Node){ // to be used inside the addNode(int) function

}

// add a node to the tree, in the correct, ordered position, given the int value parameter
void addNodeMenu(int){ // to be used in menu to call the addNode function

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

// Navigation Menu
int menu()
{
    int menu_decision = 12;
    while(menu_decision > 11 || menu_decision < 1) { // makes sure program doesn't crash
        printf("[!] ------------------------------------ Menu ---------------------------------- [!] \n");
        printf(" | • Option 1: Push to Stack \n");
        printf(" | • Option 2: Pop from Stack \n");
        printf(" | • Option 3: Empty Stack \n");
        printf("[!] ---------------------------------------------------------------------------- [!] \n");
        printf("Please return the number of the option you want to run (1-3): ");
        scanf("%d", &menu_decision);
    }
    return(menu_decision);
}

// mainline logic
int main()
{
    printf("Program Starting...\n");

    int runProgram = 1; // 0 is false 1 is true
	while(runProgram == 1)
	{
        int m = menu(); //display menu with options and store return value

        // variables and data structures used by mainline logic

        switch(m){ // program logic unfolds based on which option user chooses
            case 1:
                        }
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
