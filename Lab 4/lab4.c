/*
	Description: Lab 04
    This program utilizes linked lists to build data structures
    and performs various functions on it.
	Due Date: March 26th, 2023
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
void insertMiddle(struct Student **head, char *firstName, char *lastName, char *major, float *gpa, int position){
    struct Student *new_Student, *temp;

    new_Student = (struct Student*)malloc(sizeof(struct Student));
    strcpy(new_Student->firstName, firstName);
    strcpy(new_Student->lastName, lastName);
    strcpy(new_Student->major, major);
    new_Student->gpa = *gpa;
    new_Student->next = NULL;
    temp = *head;

    for(int i = 0; i < position-2 && temp != NULL; i++) {
        temp = temp->next;
    }
    // control flow to handle outcome if there is no way to insert into middle
    if(temp == NULL) {
        printf("The position doesn't exist in the data structure.\n");
        return;
    }
    new_Student->next = temp->next;
    temp->next = new_Student;
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
void deleteFront(struct Student **head){
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

// delete a node in the middle of the list
void deleteMiddle(struct Student **head, int position) {
    // If linked list is empty
    if (*head == NULL)
        return;

    // Store head node
    struct Student* tempHead = *head;

    // If head needs to be removed
    if (position == 0) {
        *head = tempHead->next; // Change head
        free(tempHead);         // Free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; tempHead != NULL && i < position - 2; i++)
        tempHead = tempHead->next;

    // If position is more than number of nodes
    if (tempHead == NULL || tempHead->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of the node to be deleted
    struct Student *next = tempHead->next->next;

    // Free the node to be deleted
    free(tempHead->next);

    // Unlink the deleted node from the list
    tempHead->next = next;
}

// delete a node at the end of the list
void deleteEnd(struct Student **head){
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

// traverse the list based on key value in the data portion of the node
void traverse(struct Student *head) {
    struct Student *current = head;
    printf("Traversing the list:\n");
    while (current != NULL) {
        printf("(Name: %s %s, Major: %s, GPA: %.2f) --> ", current->firstName, current->lastName, current->major, current->gpa);
        current = current->next;
    }
    printf("NULL\n");
}

// print function with different formatting to the traverse function
void printList(struct Student *head) {
    struct Student *current = head;
    printf("Here are all the students:\n");
    while (current != NULL) {
        printf("[Name: %s %s, Major: %s, GPA: %.2f], \n", current->firstName, current->lastName, current->major, current->gpa);
        current = current->next;
    }
    printf("NULL\n");
}

// find a particular node by an index number
struct Student* lookUpByIndex(struct Student* head, int index) {
    if (index < 1) {
        printf("Invalid index: %d. Index must be greater than or equal to 1.\n", index);
        return NULL;
    }

    int i = 1;
    struct Student* current = head;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Index %d out of range.\n", index);
        return NULL;
    }

    return current;
}

// print information in the current node, firstname, lastname, major, and GPA
void printStudent(struct Student *student) {
    printf("Name: %s %s\n", student->firstName, student->lastName);
    printf("Major: %s\n", student->major);
    printf("GPA: %.2f\n", student->gpa);
}

// function to get position in list for inserting student based on gpa in main
int getPosition(struct Student* head, struct Student* node) {
    int position = 1;
    while (head != NULL && head != node) {
        head = head->next;
        position++;
    }
    return position;
}

// Navigation Menu
int menu()
{
    int menu_decision = 5;
    while(menu_decision > 4 || menu_decision < 1) { // makes sure program doesn't crash
        printf("[!] ------------------------------------ Menu ---------------------------------- [!] \n");
        printf(" | • Option 1: Print all students \n");
        printf(" | • Option 2: Insert new student \n");
        printf(" | • Option 3: Delete existing student \n");
        printf(" | • Option 4: Look up student by index \n");
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
        int insertPos;
        int deletePos;

        switch(m){ // program logic unfolds based on which option user chooses
            case 1:
                printf("Choice confirmed: Print all students\n");
                printList(head);
                break;
            case 2:
                printf("Choice confirmed: Insert new students\n");
                printf("Enter first name: ");
                scanf("%s", &scanFName);
                printf("Enter last name: ");
                scanf("%s", &scanLName);
                printf("Enter abbreviated major (example: cit) : ");
                scanf("%s", &scanMajor);
                printf("Enter GPA: ");
                scanf("%f", &scanGPA);
                struct Student* new_student = (struct Student*)malloc(sizeof(struct Student));
                strcpy(new_student->firstName, scanFName);
                strcpy(new_student->lastName, scanLName);
                strcpy(new_student->major, scanMajor);
                new_student->gpa = scanGPA;
                new_student->next = NULL;

                if (head == NULL || scanGPA > head->gpa) {
                    // if list is empty or the new student has the hightest GPA
                    insertFront(&head, scanFName, scanLName, scanMajor, &scanGPA);
                } else {
                    struct Student* current_student = head;
                    while (current_student->next != NULL && current_student->next->gpa >= scanGPA) {
                        current_student = current_student->next;
                    }
                    if (current_student->next == NULL) {
                        // if the new student has the lowest GPA
                        insertEnd(&head, scanFName, scanLName, scanMajor, &scanGPA);
                    } else {
                        // if the new student's gpa is in the middle
                        insertMiddle(&head, scanFName, scanLName, scanMajor, &scanGPA, getPosition(head, current_student->next)); // uses getPostition function to pass position based on gpa
                    }
                }
                printf("New student successfully added, here's the updated list!\n");
                traverse(head);
                break;
            case 3:
                printf("Choice confirmed: Delete existing students\n");
                printf("Enter the index of the student you want to delete: ");
                scanf("%d", &deletePos);

                // Counting the number of nodes in the linked list
                int count = 0;
                struct Student *current = head;
                while(current != NULL) {
                    count++;
                    current = current->next;
                }

                // Check if the user input is within the range of the list size
                if(deletePos < 1 || deletePos > count) {
                    printf("Invalid index entered.\n");
                    break;
                }

                // Delete the node at the specified index
                if(deletePos == 1) {
                    deleteFront(&head);
                } else if(deletePos == count) {
                    deleteEnd(&head);
                } else {
                    deleteMiddle(&head, deletePos);
                }
                printf("Student deleted succesfully, here's the updated list!\n");
                traverse(head);
                break;
            case 4:
                printf("Choice confirmed: Find student by index\n");
                printf("Enter the index of the student you want to look up: ");
                int searchIndex;
                scanf("%d", &searchIndex);
                struct Student* student = lookUpByIndex(head, searchIndex);
                if (student != NULL) {
                    printf("Student details:\n");
                    printStudent(student);
                }
                break;
//            case 5:
//                printf("Choice confirmed: INSERT FRONT\n");
//                printf("Enter first name: ");
//                scanf("%s", &scanFName);
//                printf("Enter last name: ");
//                scanf("%s", &scanLName);
//                printf("Enter major: ");
//                scanf("%s", &scanMajor);
//                printf("Enter GPA: ");
//                scanf("%f", &scanGPA);
//                insertFront(&head, scanFName, scanLName, scanMajor, &scanGPA); // insert new student at the front of the list
//                traverse(head); // print the updated list
//                break;
//            case 6:
//                printf("Choice confirmed: INSERT END\n");
//                printf("Enter first name: ");
//                scanf("%s", &scanFName);
//                printf("Enter last name: ");
//                scanf("%s", &scanLName);
//                printf("Enter major: ");
//                scanf("%s", &scanMajor);
//                printf("Enter GPA: ");
//                scanf("%f", &scanGPA);
//                insertEnd(&head, scanFName, scanLName, scanMajor, &scanGPA);
//                traverse(head);
//                break;
//            case 7:
//                printf("Choice confirmed: DELETE FRONT\n");
//                deleteFront(&head); // delete the first student in the list
//                traverse(head); // print the updated list
//                break;
//            case 8:
//                printf("Choice confirmed: DELETE END\n");
//                deleteEnd(&head); // delete the last student in the list
//                traverse(head); // print the updated list
//                break;
//            case 9:
//                printf("Choice confirmed: INSERT MIDDLE\n");
//                printf("Which position would you like to insert the new student: ");
//                scanf("%d", &insertPos);
//                printf("Please enter the students details: \n");
//                printf("Enter first name: ");
//                scanf("%s", &scanFName);
//                printf("Enter last name: ");
//                scanf("%s", &scanLName);
//                printf("Enter major: ");
//                scanf("%s", &scanMajor);
//                printf("Enter GPA: ");
//                scanf("%f", &scanGPA);
//                insertMiddle(&head, scanFName, scanLName, scanMajor, &scanGPA, insertPos);
//                traverse(head);
//                break;
//            case 10:
//                printf("Choice confirmed: DELETE MIDDLE\n");
//                printf("Enter the position of student to delete: ");
//                scanf("%d", &deletePos);
//                deleteMiddle(&head, deletePos);
//                traverse(head);
//                break;
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
