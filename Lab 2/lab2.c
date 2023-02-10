/*
	Description: Lab 02
	Refactors code from Lab 1 to calculate the volume and capacity of
    a pool or hot tub given information about its dimensions.
    This lab also adds additional recursive functionality like finding
    the Sum of N, Tower of Hanoi, and Fibonacci calculations.
	Due Date: February 11th, 2023
*/
#include <stdio.h>
//global variables used or manipulated by multiple functions
double pi = 3.14159265359;
int functionCounter = 0;

// Navigation Menu
int menu()
{
    int menu_decision = 6;
    while(menu_decision > 5 || menu_decision < 1) { // makes sure program doesn't crash
        //printf("[!] Would you like to receive calculations for a hot tub or pool? (1 = Hot Tub | 2 = Pool) ");
        printf("[!] ------------------------- Menu ----------------------- [!] \n");
        printf(" | • Option 1: Run volume + capacity calculations \n");
        printf(" | • Option 2: Run Factorial function \n");
        printf(" | • Option 3: Run Towers of Hanoi \n");
        printf(" | • Option 4: Run Fibonacci Numbers \n");
        printf(" | • Option 5: Run Sum of N \n");
        printf("[!] ------------------------------------------------------ [!] \n");
        printf("Please return the number of the option you want to run (1-5): ");
        scanf("%d", &menu_decision);
    }
    switch(menu_decision){
        case 1:
            printf("  Choice selected: Hot Tub + Pool Calculations\n");
            break;
        case 2:
            printf("  Choice selected: Factorial\n");
            break;
        case 3:
            printf("  Choice selected: Towers of Hanoi\n");
            break;
        case 4:
            printf("  Choice selected: Fibonacci Numbers\n");
            break;
        case 5:
            printf("  Choice selected: Sum of N\n");
            break;
        default:
            printf("  Please type the number corresponding to the function you want to run.\n");
            scanf("%d", &menu_decision);
    }
    return(menu_decision);
}
// Function to calculate volume of hot tub
void calculate_hotTub()
{
    float h_width, h_depth;

    // declare and initialize valid input variables
    printf("  Please input a WIDTH for the hot tub between 8 and 14 feet: ");
    scanf("%f", &h_width);
    while(h_width < 8 || h_width > 14){
        printf("=== INVALID WIDTH ===\n");
        printf("  Please input a WIDTH between 8 and 14 feet: ");
        scanf("%f", &h_width);
    }
    printf("  [Hot Tub] Width: %0.2f \n", h_width);

    printf("  Please input a DEPTH for the hot tub between 3 and 5 feet: ");
    scanf("%f", &h_depth);
    while(h_depth < 3 || h_depth > 5){
        printf("=== INVALID DEPTH ===\n");
        printf("  Please input a DEPTH between 3 and 5 feet: ");
        scanf("%f", &h_depth);
    }
    printf("  [Hot Tub] Depth: %0.2f \n", h_depth);

    printf("[2] Valid Hot Tub specifications confirmed, calculating results...\n");

    float radius = h_width / 2;
    float ht_volume = pi * (radius * radius) * (h_depth-0.5);
    float ht_capacity = ht_volume * 7.481;
    float ht_capacityInQuarts = ht_capacity * 4; // used for calculating hot tub cost
    float ht_cost = ht_capacityInQuarts * 0.07;

    // Output the hot tub results
    printf("  ==================== Hot Tub Results ====================\n");
    printf("  = • The volume of the hot tub is %0.2f cubic feet. 	  =\n", ht_volume);
    printf("  = • The water capacity for it is %0.2f gallons.        =\n", ht_capacity);
    printf("  = • It would cost $%0.2f to fill this hot tub.         = \n", ht_cost);
    printf("  =========================================================\n");
}
// Function to calculate volume of pool
void calculate_pool()
{
    float p_shallowDepth, p_deepDepth, p_width, p_length, p_walkInLength, p_shallowLength, p_deepLength; // input variables

    printf("  Please input the DEPTH of the SHALLOW end of the pool between 0 and 5 feet: ");
    scanf("%f", &p_shallowDepth);
    while(p_shallowDepth < 0 || p_shallowDepth > 5){
        printf("=== INVALID DEPTH ===\n");
        printf("  Please input a DEPTH between 0 and 5 feet: ");
        scanf("%f", &p_shallowDepth);
    }
    printf("  [Pool] Shallow Depth: %0.2f \n", p_shallowDepth);


    printf("  Please input the DEPTH of the DEEP end of the pool between 6 and 15 feet: ");
    scanf("%f", &p_deepDepth);
    while(p_deepDepth < 6 || p_deepDepth > 15){
        printf("=== INVALID DEPTH ===\n");
        printf("  Please input a DEPTH between 6 and 15 feet: ");
        scanf("%f", &p_deepDepth);
    }
    printf("  [Pool] Deep Depth: %0.2f \n", p_deepDepth);


    printf("  Please input a WIDTH for the pool between 15 and 30 feet: ");
    scanf("%f", &p_width);
    while(p_width < 15 || p_width > 30){
        printf("=== INVALID WIDTH ===\n");
        printf("  Please input a WIDTH between 15 and 30 feet: ");
        scanf("%f", &p_width);
    }
    printf("  [Pool] Width: %0.2f \n", p_width);


    printf("  Please input a LENGTH for the pool between 40 and 70 feet: ");
    scanf("%f", &p_length);
    while(p_length < 40 || p_length > 70){
        printf("=== INVALID LENGTH ===\n");
        printf("  Please input a LENGTH between 40 and 70 feet: ");
        scanf("%f", &p_length);
    }
    printf("  [Pool] Length: %0.2f \n", p_length);

    printf("  Please input a LENGTH for the WALK-IN section of the pool between 5 and %0.2f feet: ", p_length/3);
    scanf("%f", &p_walkInLength);
    while(p_walkInLength < 5 || p_walkInLength > (p_length/3) ){
        printf("=== INVALID LENGTH ===\n");
        printf("  Please input a LENGTH between 5 and %f feet: ", p_length/3);
        scanf("%f", &p_walkInLength);
    }
    printf("  [Pool] Walk-In Length: %0.2f \n", p_walkInLength);


    printf("  Please input a LENGTH for the SHALLOW end between 10 and %0.2f feet: ", p_length/2);
    scanf("%f", &p_shallowLength);
    while(p_shallowLength < 10 || p_shallowLength > (p_length/2) ){
        printf("=== INVALID LENGTH ===\n");
        printf("  Please input a LENGTH between 10 and %f feet: ", p_length/2);
        scanf("%f", &p_shallowLength);
    }
    printf("  [Pool] Shallow Length: %0.2f \n", p_shallowLength);


    printf("  Please input a LENGTH for the DEEP end between 12 and %0.2f feet: ", p_length/2);
    scanf("%f", &p_deepLength);
    while(p_deepLength < 12 || p_deepLength > (p_length /2) ){
        printf("=== INVALID LENGTH ===\n");
        printf("  Please input a LENGTH between 12 and %f feet: ", p_length/2);
        scanf("%f", &p_deepLength);
    }
    printf("  [Pool] Deep Depth: %0.2f \n", p_deepLength);

    printf("[3] Valid pool specifications confirmed, calculating results...\n");

    float deepEnd_volume, shallowEnd_volume, transition_volume, entrance_volume, total_poolVolume, transition_length; //calculation variables
    transition_length = p_length - p_deepLength - p_shallowLength - p_walkInLength;

    deepEnd_volume = p_width * ((p_deepDepth-0.5) * p_deepLength);
    transition_volume = (((p_deepDepth-0.5) + (p_shallowDepth-0.5)) * (transition_length / 2)) * p_width;
    shallowEnd_volume = p_width * (p_shallowDepth-0.5) * p_shallowLength;
    entrance_volume = (((p_shallowDepth-0.5) * (p_walkInLength-0.5))/2) * p_width;

    total_poolVolume = deepEnd_volume + transition_volume + shallowEnd_volume + entrance_volume;
    float p_capacity = total_poolVolume * 7.481;
    float p_capacityInQuartz = p_capacity * 4; // used for calculating pool cost
    float p_cost = p_capacityInQuartz * 0.07;

    // Output the pool results
    printf("  ======================= Pool Results =====================\n");
    printf("  = • The volume of the pool is %0.2f cubic feet. 	   =\n",total_poolVolume);
    printf("  = • The water capacity for it is %0.2f gallons.       =\n", p_capacity);
    printf("  = • It would cost $%0.2f to fill this pool.            = \n", p_cost);
    printf("  ==========================================================\n");
}
// Calculations usage function
void calc_choice()
{
    int calc_decision = 3;
    while(calc_decision > 2 || calc_decision < 1){ // to make sure the right value is passed and the program doesn't end early
        printf("  What would you like to calculate:  \n");
        printf("  --> 1: Calculate volume and capacity of a Hot Tub. \n");
        printf("  --> 2: Calculate volume and capacity of a Pool. \n");
        printf("  Please return the number of the option you want to run (1 or 2): ");
        scanf("%d", &calc_decision);
    }
    switch(calc_decision){
        case 1:
            calculate_hotTub();
            break;
        case 2:
            calculate_pool();
            break;
    }
}
// Factorial code from the lab manual
int factorial(int n)
{
    if (n==0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}
// Towers of Hanoi Implementation
void runHanoi (int n , char x, char y, char z)
{
    // from lab manual
    if ( n == 1 )
    {
        printf("  Moved disk 1 from rod %c to rod %c\n", x, y);
    }
    else
    {
        runHanoi(n-1,x , z , y ) ;
        printf("  Moved disk %d from rod %c to rod %c\n", n, x, y);
        runHanoi(n-1,z , y , x ) ;
    }
}
// Fibonacci implementation
int fibonacci(int n){
    if (n==0){
        return 0;
    }
    else if (n==1){
        return 1;
    }
    else{
        return ( fibonacci(n-1) + fibonacci(n-2) );
    }
}
// Sum of N implementation
int runSum(int n){
    if (n!=0)
    {
        return n + runSum(n-1);
    }
    else{
        return n;
    }
}

// mainline logic
void main()
{
    printf("[1] Program Starting...\n");
    int runProgram = 1; // 0 is false 1 is true
	while(runProgram == 1)
	{
        int m = menu();
        int fact_num; // factorial
        int disk_num; // hanoi
        int fib_num;
        int fib_counter = 0; // argument passed to fib function for every iteration
        int fib_iterator; // tracks iteration in for-loop for fib
        int sum_num; // sum of n

        switch(m){
            case 1:
                calc_choice();
                functionCounter += 1;
                break;
            case 2:
                printf("  Enter the number you'd like to find the factorial for: ");
                scanf("%d", &fact_num);
                printf("  The factorial of %d is %d \n", fact_num,factorial(fact_num));
                functionCounter += 1;
                break;
            case 3:
                printf("  Enter the number of disks: ");
                scanf("%d", &disk_num);
                runHanoi(disk_num, 'a', 'c', 'b');
                functionCounter += 1;
                break;
            case 4:
                printf("  Enter a number to compute fibonacci sequence for:  ");
                scanf("%d", &fib_num);
                printf("  The first %d numbers in the Fibonacci sequence are: \n", fib_num);
                for(fib_iterator = 1; fib_iterator <= fib_num; fib_iterator ++){
                    printf("  %d\n", fibonacci(fib_counter));
                    fib_counter++;
                }
                functionCounter += 1;
                break;
            case 5:
                printf("  Enter a number to find the summation of: ");
                scanf("%d", &sum_num);
                printf("  The sum of %d is %d\n", sum_num,runSum(sum_num));
                functionCounter += 1;
                break;
            default:
                printf("You fell off the game world");
        }

		printf("[4] Do you want to run the program again? (y/n): ");
		char decision ;
		scanf(" %c", &decision);

		if (decision == 'y')
		{
			runProgram = 1;
			printf("\n");
		}
		else
		{
			runProgram = 0;
            printf("  You used a total of %d functions.\n", functionCounter);
			printf("[5] Program terminating...\n");
		}
	}
}
