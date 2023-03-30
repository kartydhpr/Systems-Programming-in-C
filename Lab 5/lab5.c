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
    char PUID[50];
    float age;
    struct Student *next;
};

// creates a list with no nodes, just a start pointer.
void createListNoNodes(struct Student **head){
    *head = NULL;
}

// creates a list with a single mode, data to fill node is a precondition and is passed as a parameter
void createListNode(struct Student **head, char *firstName, char *lastName, char *PUID, float *age) {
    struct Student *new_student = (struct student*) malloc(sizeof(struct Student)); // allocate memory for a new node
    // set new nodes data field to value from arguments
    strncpy(new_student->firstName, firstName, 50); //strncpy needs to be used to copy chars from argument to new node
    strncpy(new_student->lastName, lastName, 50);
    strncpy(new_student->PUID, PUID, 50);
    memcpy(&new_student -> age, &age, sizeof(float));
    new_student->next = NULL;
    *head = new_student;
}

// print information in the current node, firstname, lastname, major, and GPA
void printStudent(struct Student *student) {
    printf("Name: %s %s\n", student->firstName, student->lastName);
    printf("Major: %s\n", student->PUID);
    printf("GPA: %.0f\n", student->age);
}

// ------- STACK CODE -------

// insert a node at the end of the linked list
void pushLL(struct Student **head, char *firstName, char *lastName, char *PUID, float *age){
    struct Student *new_student = (struct student*) malloc(sizeof(struct Student));
    strncpy(new_student->firstName, firstName, 50);
    strncpy(new_student->lastName, lastName, 50);
    strncpy(new_student->PUID, PUID, 50);
    new_student->age = *age;
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
void popLL(struct Student **head) {
    if (*head == NULL) {
        printf("There are no students to pop from this stack...\n");
        return;
    }
    printf("Here is the student you are popping off: \n");
    struct Student *temp = *head;
    if (temp->next == NULL) { // if there is only one node in the list
        printStudent(temp);
        free(temp); // free the memory allocated for the node
        *head = NULL; // set head to NULL to indicate empty list
        printf("The last student was popped.\n");
        return;
    }
    while (temp->next->next != NULL) { // traverse to the second last node
        temp = temp->next;
    }
    struct Student *last = temp->next;
    printStudent(last);
    free(last); // free the memory allocated for the last node
    temp->next = NULL; // set the next pointer of second last node to NULL
    printf("Student popped.\n");
}

// returns the size of the stack in terms of the number of node
int sizeLL(struct Student *head){
    int count = 0;
    struct Student *current_student = head;
    while (current_student != NULL) {
        count++;
        current_student = current_student->next;
    }
    return count;
}

// Returns a boolean, true if the stack has no nodes and false if the stack has greater than 0 node
int emptyLL(struct Student *head){
    if (head == NULL) {
        return 1; // linked list is empty
    }
    else {
        return 0; // linked list is not empty
    }
}

// insert a student node at the top of the array stack
void pushA(char *arrayStack, int *arrayTop, char *firstName, char *lastName, char *PUID, float *age) {
    if (*arrayTop == 99) { // array is full
        printf("Array stack is full. Cannot push more elements.\n");
    } else {
        (*arrayTop)++; // increment top of the stack
        int index = *arrayTop * 5; // calculate index of where to add the student node

        // dynamically allocate memory for the student names
        char *first_name = (char*) malloc(sizeof(char) * 20);
        char *last_name = (char*) malloc(sizeof(char) * 20);
        strncpy(first_name, firstName, 20);
        strncpy(last_name, lastName, 20);

        // copy student data to the array stack
        memcpy(&arrayStack[index], first_name, 20);
        memcpy(&arrayStack[index + 20], last_name, 20);
        memcpy(&arrayStack[index + 40], PUID, 4);
        memcpy(&arrayStack[index + 44], age, sizeof(float));

        free(first_name);
        free(last_name);

        printf("Pushed Student: %s %s %s %f\n", firstName, lastName, PUID, *age);
    }
}

// delete a student node at the top of the array stack
void popA(char *arrayStack, int *arrayTop) {
    if (*arrayTop < 0) { // array is empty
        printf("Array stack is empty. Cannot pop more elements.\n");
    } else {
        int index = *arrayTop * 5; // calculate index of where to remove the student node

        // dynamically allocate memory for the student names
        char *first_name = (char*) malloc(sizeof(char) * 20);
        char *last_name = (char*) malloc(sizeof(char) * 20);

        memcpy(first_name, &arrayStack[index], 20);
        memcpy(last_name, &arrayStack[index + 20], 20);

        printf("Popped Student: %s %s %s %f\n", first_name, last_name, &arrayStack[index + 40], *(float*)&arrayStack[index + 44]);

        free(first_name);
        free(last_name);

        (*arrayTop)--; // decrement top of the stack
    }
}

// returns the size of the array stack in terms of the number of student nodes
int sizeA(int arrayTop){
    return arrayTop + 1;
}

// Returns a boolean, true if the array has no students and false if it has greater than 0 students
int emptyA(int arrayTop){
    return (arrayTop == -1);
}

// ------- QUEUE CODE -------

// insert a node at the end of the linked list
void enqueueLL(struct Student **head, char *firstName, char *lastName, char *PUID, float *age){
    struct Student *new_student = (struct student*) malloc(sizeof(struct Student));
    strncpy(new_student->firstName, firstName, 50);
    strncpy(new_student->lastName, lastName, 50);
    strncpy(new_student->PUID, PUID, 50);
    new_student->age = *age;
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
        printf("(Name: %s %s, PUID: %s, Age: %.0f) --> ", current->firstName, current->lastName, current->PUID, current->age);
        current = current->next; // go the next node if current is not null
    }
    printf("NULL\n");
}

// print function formatted to look like a vertical stack
void printStack(struct Student *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    printStack(head->next);
    printf("[Name: %s %s, PUID: %s, Age: %.0f], \n", head->firstName, head->lastName, head->PUID, head->age);
}

// Navigation Menu
int menu()
{
    int menu_decision = 10;
    while(menu_decision > 9 || menu_decision < 1) { // makes sure program doesn't crash
        printf("[!] ------------------------------------ Menu ---------------------------------- [!] \n");
        printf(" | -------- LL Stack Operations -------- \n");
        printf(" | • Option 1: Push to LL Stack \n");
        printf(" | • Option 2: Pop from LL Stack\n");
        printf(" | • Option 3: Size of Linked List \n");
        printf(" | • Option 4: Empty Linked List \n");
        printf(" | ------- Array Stack Operations ------- \n");
        printf(" | • Option 5: Push to Array Stack \n");
        printf(" | • Option 6: Pop from Array Stack\n");
        printf(" | • Option 7: Size of Array List \n");
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
    printf("Program Starting...\n");
    // struct head declared and list created before while loop to keep list persistent with each rerun of logic
    struct Student *head;
    createListNoNodes(&head); // create an empty linked list
    char arrayStack[100]; // // init array for array stack
    int arrayTop = -1; // to keep track of

    int runProgram = 1; // 0 is false 1 is true
	while(runProgram == 1)
	{
        int m = menu(); //display menu with options and store return value

        // variables and data structures used by mainline logic
        char scanFName[50];
        char scanLName[50];
        char scanPUID[50];
        float scanAge;

        switch(m){ // program logic unfolds based on which option user chooses
            case 1:
                printf("Choice confirmed: Push to LL Stack \n");
                printf("Enter first name: ");
                scanf("%s", &scanFName);
                printf("Enter last name: ");
                scanf("%s", &scanLName);
                printf("Enter PUID : ");
                scanf("%s", &scanPUID);
                printf("Enter age: ");
                scanf("%f", &scanAge);
                pushLL(&head, scanFName, scanLName, scanPUID, &scanAge);
                printf("Student pushed to stack\n");
                break;
            case 2:
                printf("Choice confirmed: Pop from LL Stack \n");
                popLL(&head);
                break;
            case 3:
                printf("Choice confirmed: Size of Linked List \n");
                int size = sizeLL(head);
                printf("Size of linked list: %d\n", size);
                break;
            case 4:
                printf("Choice confirmed: Empty Linked List \n");
                int listEmpty = emptyLL(head);
                if (listEmpty == 1){
                    printf("True, the linked list is empty! \n");
                }
                else if(listEmpty == 0){
                    printf("False, the linked list is not empty. \n");
                }
                break;
            case 5:
                printf("Choice confirmed: Push to Array Stack \n");
                printf("Enter first name: ");
                scanf("%s", &scanFName);
                printf("Enter last name: ");
                scanf("%s", &scanLName);
                printf("Enter PUID : ");
                scanf("%s", &scanPUID);
                printf("Enter age: ");
                scanf("%f", &scanAge);
                pushA(arrayStack, &arrayTop, scanFName, scanLName, scanPUID, &scanAge);
                break;
            case 6:
                printf("Choice confirmed: Pop from Array Stack \n");
                popA(arrayStack, &arrayTop);
                break;
            case 7:
                printf("Choice confirmed: Size of Array \n");
                printf("Size of array stack: %d\n", sizeA(arrayTop));
                break;
            case 8:
                printf("Choice confirmed: Empty Array \n");
                if (emptyA(arrayTop)) {
                    printf("True, the array stack is empty! \n");
                } else {
                    printf("False, the array stack is not empty. \n");
                }
                break;
            case 9:
                printf("Choice confirmed: Print Stack\n");
                printStack(head);
                break;
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
