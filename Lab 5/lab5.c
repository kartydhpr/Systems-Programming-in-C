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

int stackLLCounter = 0;
int stackArrCounter = 0;
int queueLLCounter = 0;
int queueArrCounter = 0;

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

// ------- STACK CODE FOR LINKED LIST AND ARRAY-------

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
    printf("Student popped from Linked List stack...\n");
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

// Empties the linked list stack
void emptyLL(struct Student **head) {
    struct Student *current = *head;
    while (current != NULL) {
        struct Student *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

// insert a student node at the top of the array stack - function completed with the help of GPT-3
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

        // printf("Pushed Student: %s %s %s %f\n", firstName, lastName, PUID, *age);
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

        // printf("Popped Student: %s %s %s %f\n", first_name, last_name, &arrayStack[index + 40], *(float*)&arrayStack[index + 44]);

        free(first_name);
        free(last_name);

        (*arrayTop)--; // decrement top of the stack
        printf("Student popped from Array stack...\n");
    }
}

// returns the size of the array stack in terms of the number of student nodes
int sizeA(int arrayTop){
    return arrayTop + 1;
}

// Empties the array stack
void emptyA(struct Student *arr[], int *top) {
    *top = -1; // reset top index to -1
    for (int i = 0; i < 100; i++) { // 100 is an arbitrary max stack size ive assigned
        arr[i] = NULL; // set all array elements to NULL
    }
}

// ------- QUEUE CODE FOR LINKED LIST AND ARRAY -------

// insert a node at the end of the linked list to mimic a queue
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

// insert a student node at the back of the array queue
void enqueueA(char *arrayQueue, int *queueFront, int *queueBack, char *firstName, char *lastName, char *PUID, float *age) {
    if (*queueBack == 99) { // queue is full
        printf("Array queue is full. Cannot enqueue more elements.\n");
    } else {
        (*queueBack)++; // increment back of the queue
        int index = *queueBack * 5; // calculate index of where to add the student node

        // dynamically allocate memory for the student names
        char *first_name = (char*) malloc(sizeof(char) * 20);
        char *last_name = (char*) malloc(sizeof(char) * 20);
        strncpy(first_name, firstName, 20);
        strncpy(last_name, lastName, 20);

        // copy student data to the array queue
        memcpy(&arrayQueue[index], first_name, 20);
        memcpy(&arrayQueue[index + 20], last_name, 20);
        memcpy(&arrayQueue[index + 40], PUID, 4);
        memcpy(&arrayQueue[index + 44], age, sizeof(float));

        free(first_name);
        free(last_name);

        // printf("Enqueued Student: %s %s %s %.0f\n", firstName, lastName, PUID, *age);
        if (*queueFront == -1) { // if the queue was previously empty
            *queueFront = 0; // set the front to the first element
        }
    }
}

// delete the first node in the list
void dequeueLL(struct Student **head){
    // check if list is empty
    if (*head == NULL) {
        printf("There are no students to delete....\n");
        return;
    }
    printf("Here is the student you are dequeue-ing: \n");

    // store the first node in a temporary variable
    struct Student *temp = *head;
    printStudent(temp);
    // move the head to point to the second node
    *head = (*head)->next;
    // free the memory allocated to the first node
    free(temp);
    printf("Dequeued the first student in the linked list.\n");
}

// remove and return the first student node from the array stack - function completed with the help of GPT-3
void dequeueA(char arrayQueue[], int* front, int* back) {
    if (*front == -1) { // check if queue is empty
        printf("Queue is empty\n");
    } else {
        printf("Dequeued element from array: %c\n", arrayQueue[*front]); // print dequeued element
        if (*front == *back) { // reset front and back if there is only one element
            *front = -1;
            *back = -1;
        } else {
            *front = (*front + 1) % sizeof(arrayQueue); // move front to the next element in the circular array
        }
    }
}

// print function formatted to look like a horizontal queue
void printQueue(struct Student *head) {
    struct Student *current = head;
    while (current != NULL) {
        printf("(Name: %s %s, PUID: %s, Age: %.0f) <-- ", current->firstName, current->lastName, current->PUID, current->age);
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
    int menu_decision = 12;
    while(menu_decision > 11 || menu_decision < 1) { // makes sure program doesn't crash
        printf("[!] ------------------------------------ Menu ---------------------------------- [!] \n");
        printf(" | -------- Stack Operations -------- \n");
        printf(" | • Option 1: Push to Stack \n");
        printf(" | • Option 2: Pop from Stack \n");
        printf(" | • Option 3: Empty Stack \n");
        printf(" | • Option 4: Print Stack \n");
        printf(" | ------- Queue Operations ------- \n");
        printf(" | • Option 5: Enqueue Queue \n");
        printf(" | • Option 6: Dequeue Queue\n");
        printf(" | • Option 7: Empty Queue \n");
        printf(" | • Option 8: Print Queue \n");
        printf(" | --- Stack + Queue Operations --- \n");
        printf(" | • Option 9: Add Element (Push and Enqueue) \n");
        printf(" | • Option 10: Remove Element (Pop and Dequeue) \n");
        printf(" | • Option 11: Number of moves so far \n");
        printf("[!] ---------------------------------------------------------------------------- [!] \n");
        printf("Please return the number of the option you want to run (1-11): ");
        scanf("%d", &menu_decision);
    }
    return(menu_decision);
}

// mainline logic
int main()
{
    printf("Program Starting...\n");
    // struct heads declared and lists created before while loop to keep list persistent with each rerun of while logic
    struct Student *head;
    struct Student *queueHead;
    createListNoNodes(&head); // create an empty linked list for the stack
    createListNoNodes(&queueHead); // create an empty linked list for the queue

    char arrayStack[100]; // // init array for array stack
    int arrayTop = -1; // to keep track of

    char arrayQueue[100];
    int queueFront = -1; // initialize the front and back of the queue
    int queueBack = -1;
    int sizeQArr = sizeof(arrayQueue) / sizeof(arrayQueue[0]);


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
                printf("Choice confirmed: Pushing to Linked List and Array Stack \n");
                printf("Enter first name: ");
                scanf("%s", &scanFName);
                printf("Enter last name: ");
                scanf("%s", &scanLName);
                printf("Enter PUID : ");
                scanf("%s", &scanPUID);
                printf("Enter age: ");
                scanf("%f", &scanAge);
                pushLL(&head, scanFName, scanLName, scanPUID, &scanAge);
                stackLLCounter ++;
                printf("Student pushed to Linked List Stack...\n");
                pushA(arrayStack, &arrayTop, scanFName, scanLName, scanPUID, &scanAge);
                stackArrCounter ++;
                printf("Student pushed to Array Stack...\n");
                break;
            case 2:
                printf("Choice confirmed: Popping from Linked list and Array Stack \n");
                popLL(&head);
                stackLLCounter ++;
                popA(arrayStack, &arrayTop);
                stackArrCounter ++;
                break;
            case 3:
                printf("Choice confirmed: Emptying Linked List and Array stacks \n");
                emptyLL(&head);
                printf("Linked List stack emptied...\n");
                emptyA(arrayStack, &arrayTop);
                printf("Array stack emptied...\n");
                break;
            case 4:
                printf("Choice confirmed: Printing Stack \n");
                int size = sizeLL(head);
                printStack(head);
                printf("Size of linked list stack: %d\n", size);
                printf("Size of array stack: %d\n", sizeA(arrayTop));
                break;
            case 5:
                printf("Choice confirmed: En-queueing Linked List and Array queues \n");
                printf("Enter first name: ");
                scanf("%s", &scanFName);
                printf("Enter last name: ");
                scanf("%s", &scanLName);
                printf("Enter PUID : ");
                scanf("%s", &scanPUID);
                printf("Enter age: ");
                scanf("%f", &scanAge);
                enqueueLL(&queueHead, scanFName, scanLName, scanPUID, &scanAge);
                queueLLCounter ++;
                printf("Student enqueued to Linked List queue...\n");
                enqueueA(arrayQueue, &queueFront, &queueBack, scanFName, scanLName, scanPUID, &scanAge);
                queueArrCounter ++;
                printf("Student enqueued to Array queue...\n");
                break;
            case 6:
                printf("Choice confirmed: De-queueing Linked List and Array queues \n");
                dequeueLL(&queueHead);
                queueLLCounter ++;
                printf("Student dequeued from Linked List queue...\n");
                dequeueA(arrayQueue, &queueFront, &queueBack);
                queueArrCounter ++;
                printf("Student dequeued from Array queue...\n");
                break;
            case 7:
                printf("Choice confirmed: Emptying Linked List and Array queues\n");
                emptyLL(&queueHead);
                printf("Linked List queue emptied...\n");
                emptyA(arrayQueue, &arrayTop);
                printf("Array stack emptied...\n");
                break;
            case 8:
                printf("Choice confirmed: Printing Queue\n");
                printQueue(queueHead);
                break;
            case 9:
                printf("Choice confirmed: Adding elements to Linked List and Array stacks and queues\n");
                printf("Enter first name: ");
                scanf("%s", &scanFName);
                printf("Enter last name: ");
                scanf("%s", &scanLName);
                printf("Enter PUID : ");
                scanf("%s", &scanPUID);
                printf("Enter age: ");
                scanf("%f", &scanAge);
                pushLL(&head, scanFName, scanLName, scanPUID, &scanAge);
                stackLLCounter ++;
                printf("Pushed to linked list stack\n");
                pushA(arrayStack, &arrayTop, scanFName, scanLName, scanPUID, &scanAge);
                stackArrCounter ++;
                printf("Pushed to array stack\n");
                enqueueLL(&queueHead, scanFName, scanLName, scanPUID, &scanAge);
                queueLLCounter ++;
                printf("Enqueued to linked list queue\n");
                enqueueA(arrayQueue, &queueFront, &queueBack, scanFName, scanLName, scanPUID, &scanAge);
                queueArrCounter ++;
                printf("Enqueued to array queue...\n");
                break;
            case 10:
                printf("Choice confirmed: Removing elements from Linked List and Array stacks and queues\n");
                popLL(&head);
                stackLLCounter ++;
                popA(arrayStack, &arrayTop);
                stackArrCounter ++;
                dequeueLL(&queueHead);
                queueLLCounter ++;
                dequeueA(arrayQueue, &queueFront, &queueBack);
                queueArrCounter ++;
                break;
            case 11:
                printf("Choice confirmed: Returning number of moves so far for Linked List and Array\n");
                printf("Number of moves made on Linked List stack: %d\n", stackLLCounter);
                printf("Number of moves made on Array stack: %d\n", stackLLCounter);
                printf("Number of moves made on Linked List queue: %d\n", queueLLCounter);
                printf("Number of moves made on Array queue: %d\n", queueArrCounter);
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
