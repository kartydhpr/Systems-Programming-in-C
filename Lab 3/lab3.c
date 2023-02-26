/*
	Description: Lab 03
    This program utilizes pointers and 3 sorting algorithms;
    the Bubble, Selection and Quick Sort to manipulate Arrays
    and Strings in ANSI C.
	Due Date: February 25th, 2023
*/

/* =========================== Sorting Algorithm Analysis: ============================
 *  BUBBLE SORT:
 *  Number of moves to sort an array with 10 elements in desc. order when input is:
 *    • A completely sorted array (10,9,8,7,6,5,4,3,2,1)     : 0 moves
 *    • An almost sorted array (10,9,8,7,6,5,3,4,1,2)        : 2 moves
 *    • About half-sorted array (10,9,8,7,6,1,2,3,4,5)       : 10 moves
 *    • Completely unsorted array (1,2,3,4,5,6,7,8,9,10)     : 45 moves
 *
 *  SELECTION SORT:
 *  Number of moves to sort an array with 10 elements in desc. order when input is:
 *    • A completely sorted array (10,9,8,7,6,5,4,3,2,1)     : 0 moves
 *    • An almost sorted array (10,9,8,7,6,5,3,4,1,2)        : 2 moves
 *    • About half-sorted array (10,9,8,7,6,1,2,3,4,5)       : 6 moves
 *    • Completely unsorted array (1,2,3,4,5,6,7,8,9,10)     : 25 moves
 *
 *  QUICK SORT:
 *  Number of moves to sort an array with 10 elements in desc. order when input is:
 *    • A completely sorted array (10,9,8,7,6,5,4,3,2,1)     : 6 moves
 *    • An almost sorted array (10,9,8,7,6,5,3,4,1,2)        : 7 moves
 *    • About half-sorted array (10,9,8,7,6,1,2,3,4,5)       : 8 moves
 *    • Completely unsorted array (1,2,3,4,5,6,7,8,9,10)     : 11 moves
 *
 *  CONCLUSION:
 *  Bubble Sort: Works the quickest when it receives sorted array or almost sorted
 *               array as input. Slowest when reversely sorted or most elements in
 *               the wrong order.
 *  Selection Sort: Similar to bubble sort when it receives already sorted or
 *                  mostly sorted array as input. Takes lesser moves to reorder than
 *                  Bubble Sort when there is more completely unsorted elements.
 *  Quick Sort: Definitely the quickest sorting technique with the least amount of
 *              moves for larger arrays with more unsorted elements. The divide
 *              and conquer nature of this algorithm is what makes it have more moves
 *              initially even when the inputted array is completely or almost sorted.
 *
 ===================================================================================*/

#include <stdio.h>
#include <string.h>
//global variables
   int bubble_moves=0;
   int selection_moves=0;
   int quick_moves=0;

// Navigation Menu
int menu()
{
    int menu_decision = 3;
    while(menu_decision > 2 || menu_decision < 1) { // makes sure program doesn't crash
        printf("[!] ------------------------------------ Menu ---------------------------------- [!] \n");
        printf(" | • Option 1: Run sorting algorithms on an array and compare number of moves \n");
        printf(" | • Option 2: Use recursion to reverse a string and check if it is a palindrome \n");
        printf("[!] ---------------------------------------------------------------------------- [!] \n");
        printf("Please return the number of the option you want to run (1 or 2): ");
        scanf("%d", &menu_decision);
    }
    if(menu_decision == 1){
        printf("    Choice confirmed: Sorting Arrays\n");
    }
    else if(menu_decision == 2){
        printf("    Choice confirmed: Reversing Strings\n");
    }
    else{
        printf("= Unexpected error =");
    }
    return(menu_decision);
}

// swap function for sorting algorithms
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int old_arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 1; j < size; j ++)
        {
            if(old_arr[j] > old_arr[j-1])
            {
                swap(&old_arr[j], &old_arr[j-1]);
                bubble_moves += 1;
            }
        }
    }
}

// Selection Sort
void selectionSort(int old_arr[], int size) {
    int i, j, min_idx;
    // Move the boundary of the unsorted subarray one-by-one
    for (i = 0; i < size-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (old_arr[j] > old_arr[min_idx]){
                min_idx = j;
                selection_moves += 1; // add to the move counter
            }
        // Swap the found minimum element with the first element
        swap(&old_arr[min_idx], &old_arr[i]);
    }
}

// Quick Sort
void quickSort(int arr[], int left, int right) {
    int i = left, j = right; // Initialize two pointers, i and j, to the left and right ends of the current subarray
    int pivot = arr[(left + right) / 2]; // Choose a pivot element, here we choose the middle element
    while (i <= j) { // While the pointers haven't crossed each other
        while (arr[i] > pivot) { // Move the left pointer to the right until we find an element that is less than or equal to the pivot
            i++;
        }
        while (arr[j] < pivot) { // Move the right pointer to the left until we find an element that is greater than or equal to the pivot
            j--;
        }
        if (i <= j) { // If the pointers haven't crossed each other, and we've found two elements to swap
            swap(&arr[i], &arr[j]); // Swap the two elements
            i++; // Move the left pointer to the right
            j--; // Move the right pointer to the left
            quick_moves+=1;
        }
    }
    if (left < j) { // If there are still unsorted elements to the left of the current subarray
        quickSort(arr, left, j); // Recursively sort the subarray to the left of the pivot
    }
    if (i < right) { // If there are still unsorted elements to the right of the current subarray
        quickSort(arr, i, right); // Recursively sort the subarray to the right of the pivot
    }
}

// Print Array function for main
void printArr(int arr[], int arr_len){
    for(int i = 0; i < arr_len; i++)
    {
        if(i == arr_len-1)
        {
            printf("%d\n", arr[i]);
        }
        else{
            printf("%d, ", arr[i]);
        }
    }
}

// Pass-by-Value String Reversal Implementation
void passByValueReversal(char str[], int start, int end) {
    if (start>=end) // this is the base case
    {
        return;
    }
    // swap characters at the beginning and end of string
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    // run function again recursively to swap 1 character after the start and 1 before the end of the last call
    passByValueReversal(str, start + 1, end - 1);
}

// Pass-by-Reference String Reversal Implementation
void passByRefReversal(char *str) {
    if(*str){ // checks to see if pointer points to a non empty string i.e not null
        passByRefReversal(str+1); // recursive call to the function with the address of the second character in string
        printf("%c", *str); // print character
    }
}

// Palindrome implementation
int isPalindrome(char *str, int left, int right){
    if(str == NULL || left < 0 || right < 0 ){  // If the input is invalid or the substring is empty, it is not a palindrome
        return 0;
    }
    if(left >= right){  // If the substring has only one character or no characters, it is a palindrome
        return 1;
    }
    if(str[left] == str[right]){ // If the first and last characters of the substring are equal, check if the substring minus the first and last characters is also a palindrome
        return isPalindrome(str, left+1, right-1);
    }
    return 0;
}

// mainline logic
int main()
{
    printf("[0] Program Starting...\n");
    int runProgram = 1; // 0 is false 1 is true
	while(runProgram == 1)
	{
        int m = menu(); //display menu with options

        // variables and data structures used by mainline logic
        int array_length = 0;
        int input_array[100];
        int bubble_arr[100];
        int sel_arr[100];
        int quick_arr[100];
        char inputString[100]; // for option 2
        char refString[100];
        char palinString[100];

        switch(m){ // program logic unfolds based on which option user chooses
            case 1:
                // input capture and validation
                printf("    Please enter the size of the array: ");
                scanf("%d", &array_length);
                printf("    Please enter %d numbers\n", array_length);
                for(int i =0; i < array_length; i++){
                    printf("       Enter a number: ");
                    scanf("%d", &input_array[i]);
                }

                // copy values from input_array into 3 different arrays for each sort
                for(int i = 0; i < array_length; i++)
                {
                    bubble_arr[i] = input_array[i];
                    sel_arr[i] = input_array[i];
                    quick_arr[i] = input_array[i];
                }

                // execute Bubble Sort:
                printf("[1] Executing Bubble Sort to order the following array in descending order:\n    ");
                printArr(input_array, array_length);
                bubbleSort(bubble_arr, array_length);
                printf("    Bubble Sorted array: \n    ");
                printArr(bubble_arr, array_length);
                printf("--> Array sorted in: [%d moves]\n", bubble_moves);

                // execute Selection Sort:
                printf("[2] Executing Selection Sort to order the following array in descending order:\n    ");
                printArr(sel_arr, array_length);
                selectionSort(sel_arr, array_length);
                printf("    Selection Sorted array: \n    ");
                printArr(sel_arr, array_length);
                printf("--> Array sorted in: [%d moves]\n", selection_moves);

                // execute Quick Sort:
                printf("[3] Executing Quick Sort to order the following array in descending order:\n    ");
                printArr(quick_arr, array_length);
                quickSort(quick_arr, 0, array_length-1);
                printf("    Quick Sorted array: \n    ");
                printArr(quick_arr, array_length);
                printf("--> Array sorted in: [%d moves]\n", quick_moves);

                break;
            case 2:
                getchar();
                printf("[1] Please enter a string of words to reverse: ");
                fgets(inputString, sizeof(inputString), stdin);
                // copy input string into refString to be used for pass by reference function
                for(int i = 0; i < sizeof(inputString); i++){
                    refString[i] = inputString[i];
                    palinString[i] = inputString[i];
                }
                printf("[2] Reversing string using Pass-by-Value... ");
                passByValueReversal(inputString, 0, strlen(inputString)-1);
                printf("%s\n", inputString);
                printf("[3]Reversing string using Pass-by-Reference...");
                passByRefReversal(refString);
                //check isPalindrome result for palindrome and print statement accordingly
                if(isPalindrome(palinString, 0, strlen(palinString)-2) == 1){
                    printf("\n--> This string is a palindrome.");
                }
                else{
                    printf("\n--> This string is not a palindrome.");
                }
                printf("\n");
                break;
            default:
                printf("You're not supposed to be here...");
        }

		printf("[4] Do you want to run the program again? (y/n): ");
		char decision ;
		scanf(" %c", &decision);

		if (decision == 'y')
		{
			runProgram = 1;
            // clears the number of moves for each array when program is rerun in same session
            bubble_moves=0;
            selection_moves=0;
            quick_moves=0;

            // empties all arrays for next round of tests
            for(int i = 0; i < array_length; i ++){
                input_array[i] = 0;
                bubble_arr[i] = 0;
                sel_arr[i] = 0;
                quick_arr[i] = 0;
            }
			printf("\n");
		}
		else
		{
			runProgram = 0;
			printf("[5] Program terminating...\n");
		}
	}
}
