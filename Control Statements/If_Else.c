#include<stdio.h>

void main() {
	int a, b, choice;

	// printf("\nEnter a and b: ");
	// scanf("%d %d", &a, &b);

	// printf("\na = %d\t&a = %u", a, &a);
	// printf("\nb = %d\t&b = %u\n\n", b, &b);

	// if(a>b) {
	// 	printf("%d > %d", a, b);
	// } else if(a<b) {
	// 	printf("%d < %d", a, b);
	// } else {
	// 	printf("%d < %d", a, b);
	// }

	// printf("\n1. Addition");
	// printf("\n2. Subtraction");
	// printf("\n3. Multiplication");
	// printf("\n4. Division");
	// printf("\n5. Remainder");
	// printf("\nEnter your choice: ");
	// scanf("%d", &choice);
	
	// if(choice == 1) {
	// 	printf("%d + %d = %d", a, b, a+b);
	// } else if(choice == 2) {
	// 	printf("%d - %d = %d", a, b, a-b);
	// } else if(choice == 3) {
	// 	printf("%d * %d = %d", a, b, a*b);
	// } else if(choice == 4) {
	// 	printf("%d / %d = %d", a, b, a/b);
	// } else if(choice == 5) {
	// 	printf("%d (mod) %d = %d", a, b, a%b);
	// }

	do {
		printf("\nEnter a and b: ");
		scanf("%d %d", &a, &b);

		printf("\n1. Addition");
		printf("\n2. Subtraction");
		printf("\n3. Multiplication");
		printf("\n4. Division");
		printf("\n5. Remainder");
		printf("\n6. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("%d + %d = %d", a, b, a+b);
				break;
			case 2:
				printf("%d - %d = %d", a, b, a-b);
				break;
			case 3:
				printf("%d * %d = %d", a, b, a*b);
				break;
			case 4:
				printf("%d / %d = %d", a, b, a/b);
				break;
			case 5:
				printf("%d %c %d = %d", a, '%', b, a%b);
				break;

			case 6:
				printf("\nThank you!!!");
				break;

			default:
				printf("\nInvalid choice...");
		}
	} while(choice != 6);

}





/*
Control Statements:-
	-> these statements controls the flow of the program.

1. if statement:-
	-> used when the program have to make a decision.
4 ways of using these if statements
	1. If statement Only
	-> syntax:-
		if(condition){
			//body of the if statement
		}

	2. if else statement
	->syntax:-
		if(condition){
			//if block
		}else{
			//body of else block
		}

	3. if else if statement (ladder if statement)
	->syntax:-
		if(condition_1){
			//if block
		}else if(condition_2){
			//else block
		}else if(condition_3){
			//else block
		}else{
			//else block
		}


	4. nested if statements
	-> syntax:-
		if(condition){
			if(condition){	//nested if
				//nested if block
			}else{
				//nested else block
			}
		}else{
			//else block
		}


2. Switch Case
3. LOOPS
4. break, continue, goto statements

*/