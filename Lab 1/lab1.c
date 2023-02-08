/*
    Author: Karteikay Dhuper
	Description: Lab 01
	This program calculates the volume, capacity, and cost required
	to fill a pool and a hot tub given information about its dimensions.
	Due Date: Jan 28th, 2023
*/
#include <stdio.h>

int main()
{
	int runProgram = 1; // 0 is false 1 is true
	while(runProgram == 1)
	{
		printf("[1] Program Starting...\n");
		// declare and initialize valid input variables
		float h_width, h_depth, p_shallowDepth, p_deepDepth, p_width, p_length, p_walkInLength, p_shallowLength, p_deepLength;
		
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

        printf("[2] Valid Hot Tub specifications confirmed, please provide pool specs...\n");

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

        // Calculate volume of hot tub
		double pi = 3.14159265359;
		float radius = h_width / 2;
		float ht_volume = pi * (radius * radius) * (h_depth-0.5);
		float ht_capacity = ht_volume * 7.481;
		float ht_capacityInQuarts = ht_capacity * 4; // used for calculating hot tub cost
		float ht_cost = ht_capacityInQuarts * 0.07;

        // Calculate volume of pool

        float deepEnd_volume, shallowEnd_volume, transition_volume, entrance_volume, total_poolVolume;
        float transition_length = p_length - p_deepLength - p_shallowLength - p_walkInLength;
        
        deepEnd_volume = p_width * ((p_deepDepth-0.5) * p_deepLength);
        transition_volume = (((p_deepDepth-0.5) + (p_shallowDepth-0.5)) * (transition_length / 2)) * p_width;
        shallowEnd_volume = p_width * (p_shallowDepth-0.5) * p_shallowLength;
        entrance_volume = (((p_shallowDepth-0.5) * (p_walkInLength-0.5))/2) * p_width;
        
        total_poolVolume = deepEnd_volume + transition_volume + shallowEnd_volume + entrance_volume;
        float p_capacity = total_poolVolume * 7.481;
        float p_capacityInQuartz = p_capacity * 4; // used for calculating pool cost
        float p_cost = p_capacityInQuartz * 0.07;

		// Output the hot tub results
		printf("  ==================== Hot Tub Results ====================\n");
		printf("  = • The volume of the hot tub is %0.2f cubic feet. 	 =\n",ht_volume);
		printf("  = • The water capacity for it is %0.2f gallons.          =\n", ht_capacity);
		printf("  = • It would cost $%0.2f to fill this hot tub.         = \n", ht_cost);
		printf("  =========================================================\n");

        // Output the pool results
        printf("  ===================== Pool Results =====================\n");
        printf("  = • The volume of the pool is %0.2f cubic feet. 	  =\n",total_poolVolume);
        printf("  = • The water capacity for it is %0.2f gallons.         =\n", p_capacity);
        printf("  = • It would cost $%0.2f to fill this pool.           = \n", p_cost);
        printf("  =========================================================\n");

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
			printf("[5] Program terminating...\n");
		}
	}
}
