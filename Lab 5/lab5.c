/*
	Description: Lab 05
    This program utilizes linked lists and arrays to build data structures of
    students and their information and perform Stack and Queue operations on them.
	Due Date: April 8th, 2023
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

// ------- STACK CODE -------

// insert a node at the end of the linked list
void pushLL(struct Student **head, char *firstName, char *lastName, char *major, float *gpa){
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

// delete a node at the end of the list
void popLL(struct Student **head){
    if (*head == NULL) {
        printf("There are no students to delete...\n");
        return;
    }

    if ((*head)->next == NULL) { // if there is only one node in the list
        free(*head); // free the memory allocated for the node
        *head = NULL; // set head to NULL to indicate empty list
        return;
    }

    struct Student *temp = *head;
    while (temp->next->next != NULL) { // traverse to the second last node
        temp = temp->next;
    }

    free(temp->next); // free the memory allocated for the last node
    temp->next = NULL; // set the next pointer of second last node to NULL
}


// ------- QUEUE CODE -------

// insert a node at the end of the linked list
void enqueueLL(struct Student **head, char *firstName, char *lastName, char *major, float *gpa){
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
void dequeueLL(struct Student **head){
    // check if list is empty
    if (*head == NULL) {
        printf("There are no students to delete....\n");
        return;
    }
    // store the first node in a temporary variable
    struct Student *temp = *head;
    // move the head to point to the second node
    *head = (*head)->next;
    // free the memory allocated to the first node
    free(temp);
    printf("Deleted the first student in the list.\n");
}



// print function formatted to look like a horizontal queue
void printQueue(struct Student *head) {
    struct Student *current = head;
    printf("Traversing the list:\n");
    while (current != NULL) {
        printf("(Name: %s %s, Major: %s, GPA: %.2f) --> ", current->firstName, current->lastName, current->major, current->gpa);
        current = current->next; // go the next node if current is not null
    }
    printf("NULL\n");
}

// print function formatted to look like a vertical stack
void printStack(struct Student *head) {
    struct Student *current = head;
    printf("Here are all the students:\n");
    while (current != NULL) {
        printf("[Name: %s %s, Major: %s, GPA: %.2f], \n", current->firstName, current->lastName, current->major, current->gpa);
        current = current->next;
    }
    printf("NULL\n");
}

// print information in the current node, firstname, lastname, major, and GPA
void printStudent(struct Student *student) {
    printf("Name: %s %s\n", student->firstName, student->lastName);
    printf("Major: %s\n", student->major);
    printf("GPA: %.2f\n", student->gpa);
}

// Navigation Menu
int menu()
{
    int menu_decision = 10;
    while(menu_decision > 9 || menu_decision < 1) { // makes sure program doesn't crash
        printf("[!] ------------------------------------ Menu ---------------------------------- [!] \n");
        printf(" | ------- Stack Operations ------- \n");
        printf(" | • Option 1: Push to LL Stack \n");
        printf(" | • Option 2: Pop from LL Stack\n");
        printf(" | • Option 3: Size of Linked List \n");
        printf(" | • Option 4: Empty Linked List \n");
        printf(" | • Option 5: Push to Array Stack \n");
        printf(" | • Option 6: Pop from Array Stack\n");
        printf(" | • Option 7: Size of Aray List \n");
        printf(" | • Option 8: Empty Array List \n");
        printf(" | • Option 9: Print Stack \n");
        printf("[!] ---------------------------------------------------------------------------- [!] \n");
        printf("Please return the number of the option you want to run (1-9): ");
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
                printf("Choice confirmed: Push to LL Stack \n");
                printf("Enter first name: ");
                scanf("%s", &scanFName);
                printf("Enter last name: ");
                scanf("%s", &scanLName);
                printf("Enter abbreviated major (example: cit) : ");
                scanf("%s", &scanMajor);
                printf("Enter GPA: ");
                scanf("%f", &scanGPA);
                break;
            case 2:
                printf("Choice confirmed: Pop from LL Stack \n");
                break;
            case 3:
                printf("Choice confirmed: Size of Linked List \n");
                break;
            case 4:
                printf("Choice confirmed: Empty Linked List \n");
                break;
            case 5:
                printf("Choice confirmed: Push to Array Stack \n");
                printf("Enter first name: ");
                scanf("%s", &scanFName);
                printf("Enter last name: ");
                scanf("%s", &scanLName);
                printf("Enter abbreviated major (example: cit) : ");
                scanf("%s", &scanMajor);
                printf("Enter GPA: ");
                scanf("%f", &scanGPA);
                break;
            case 6:
                printf("Choice confirmed: Pop from Array Stack \n");
                break;
            case 7:
                printf("Choice confirmed: Size of Array \n");
                break;
            case 8:
                printf("Choice confirmed: Empty Array \n");
                break;
            case 9:
                printf("Choice confirmed: Print Stack\n");

                break;
        }
		printf("[4] Do you want to run the program again? (y/n): ");
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
