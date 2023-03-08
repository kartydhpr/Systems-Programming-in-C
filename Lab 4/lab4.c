/*
	Description: Lab 04
    This program utilizes linked lists to build data structures
    and performs various functions on it.
	Due Date: February 25th, 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global variables

struct Student{
    char firstName[50];
    char lastName[50];
    char major[50];
    float gpa;
    struct Student *next;
};

// creates a list with no nodes, just a start pointer.
void createListNoNodes(struct Student **head){
    *head = NULL;
}

// creates a list with a single mode, data to fill node is a precondition and is passed as a parameter
void createListNode(struct Student **head, char *firstName, char *lastName, char *major, float *gpa) {
    struct Student *new_student = (struct student*) malloc(sizeof(struct Student)); // allocate memory for a new node
    // set new nodes data field to value from arguments
    strncpy(new_student->firstName, firstName, 50); //strncpy needs to be used to copy chars from argument to new node
    strncpy(new_student->lastName, lastName, 50);
    strncpy(new_student->major, major, 50);
    memcpy(&new_student -> gpa, &gpa, sizeof(float));
    new_student->next = NULL;
    *head = new_student;
}

// insert a node at the front of the list
void insertFront(struct Student **head, char *firstName, char *lastName, char *major, float *gpa){
    struct Student *new_student = (struct student*) malloc(sizeof(struct Student));
    strncpy(new_student->firstName, firstName, 50);
    strncpy(new_student->lastName, lastName, 50);
    strncpy(new_student->major, major, 50);
    new_student->gpa = *gpa;
    new_student->next = *head;
    *head = new_student;
}
// insert a node in the middle of the list
void insertMiddle(){

}

// insert a node at the end of the list
void insertEnd(struct Student **head, char *firstName, char *lastName, char *major, float *gpa){
    struct Student *new_student = (struct student*) malloc(sizeof(struct Student));
    strncpy(new_student->firstName, firstName, 50);
    strncpy(new_student->lastName, lastName, 50);
    strncpy(new_student->major, major, 50);
    new_student->gpa = *gpa;
    new_student->next = NULL;
    // if list is empty set header pointer to point to the new node
    if (*head == NULL) {
        *head = new_student;
        return;
    }
    // if not empty then traverse list to find last node
    struct Student *current_student = *head;
    while (current_student->next != NULL) {
        current_student = current_student->next;
    }
    current_student->next = new_student; // set next pointer of last node to point to new node
}

// delete the first node in the list
void deleteFront(){

}

// delete a node in the middle of the list
void deleteMiddle(){

}

// delete a node at the end of the list
void deleteEnd(){

}

// traverse the list based on key value in the data portion of the node
void traverse(){

}

// find a particular node by an index number, returns 1- if index doesn't exist
void lookUpByIndex(){

}

// print information in the current node, firstname, lastname, major, and GPA
void printNode(){

}

void printList(struct Student *start){
    // Traverse the list and print the data in each node.
    struct Student *current_student = start;
    while (current_student != NULL) {
        printf("(%s, %s, %s, %f) -> ", current_student->firstName, current_student->lastName, current_student->major, current_student->gpa);
        current_student = current_student->next;
    }
    printf("NULL\n");
}
// Navigation Menu
int menu()
{
    int menu_decision = 5;
    while(menu_decision > 4 || menu_decision < 1) { // makes sure program doesn't crash
        printf("[!] ------------------------------------ Menu ---------------------------------- [!] \n");
        printf(" | • Option 1: Print all students \n");
        printf(" | • Option 2: INSERT FRONT \n");
        printf(" | • Option 3: INSERT BACK \n");
        printf(" | • Option 4: Find a particular student \n");
        printf("[!] ---------------------------------------------------------------------------- [!] \n");
        printf("Please return the number of the option you want to run (1-4): ");
        scanf("%d", &menu_decision);
    }
    return(menu_decision);
}

// mainline logic
int main()
{
    printf("[0] Program Starting...\n");
    // struct head declared and list created before while loop to keep list persistent with each rerun of logic
    struct Student *head;
    createListNoNodes(&head); // create an empty list

    int runProgram = 1; // 0 is false 1 is true
	while(runProgram == 1)
	{
        int m = menu(); //display menu with options and store return value

        // variables and data structures used by mainline logic
        char scanFName[50];
        char scanLName[50];
        char scanMajor[50];
        float scanGPA;

        switch(m){ // program logic unfolds based on which option user chooses
            case 1:
                printf("Choice confirmed: Print all students\n");
                break;
            case 2:
                printf("Choice confirmed: INSERT FRONT\n");
                printf("Enter first name: ");
                scanf("%s", &scanFName);
                printf("Enter last name: ");
                scanf("%s", &scanLName);
                printf("Enter major: ");
                scanf("%s", &scanMajor);
                printf("Enter GPA: ");
                scanf("%f", &scanGPA);
                insertFront(&head, scanFName, scanLName, scanMajor, &scanGPA); // insert new student at the front of the list
                printList(head); // print the updated list
                break;
            case 3:
                printf("Enter first name: ");
                scanf("%s", &scanFName);
                printf("Enter last name: ");
                scanf("%s", &scanLName);
                printf("Enter major: ");
                scanf("%s", &scanMajor);
                printf("Enter GPA: ");
                scanf("%f", &scanGPA);
                insertEnd(&head, scanFName, scanLName, scanMajor, &scanGPA);
                printList(head);
                break;
            case 4:
                printf("Choice confirmed: Find a student\n");
                break;
        }
		printf("[4] Do you want to run the program again? (y/n): ");
		char decision ;
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
