#include<stdio.h>

void add();
void sub(int, int);
double mul();
float div(float a, float b) {
    return a/b;
}

void main() {
    int a, b;
    printf("\nEnter a and b: ");
    scanf("%d %d", &a, &b);

    add();
    sub(a, b);
    printf("\nmul() = %lf", mul());
    printf("\ndiv() = %f", div(a, b));
}

void add() {
    int a, b;
    printf("\nEnter a and b: ");
    scanf("%d %d", &a, &b);
    printf("\n");

    printf("\n%d + %d = %d", a, b, a+b);
}

void sub(int x, int y) {
    printf("\n%d - %d = %d", x, y, x-y);
}

double mul() {
    int a, b;
    printf("\nEnter a and b: ");
    scanf("%d %d", &a, &b);
    return a*b;
}


/*
Functions are used to perform a specific task. They are also called subroutines or procedures.

Functions are like assistants who work for you. They perform a specific task and return the result to the main program.

In C Functions are of two types:
1. Built-in Functions -> These are the functions which are already defined in the C language. For example, printf() is a built-in function.

2. User-defined Functions -> These are the functions which are defined by the user.

Syntax of a Function:

return_type function_name (parameter list(optional)) {
    // body of the function
}

we have 4 categories of user-defined functions:
1. No argument and no return type
2. No argument and return type
3. Argument and no return type
4. Argument and return type


3 steps to use any function:

1. Declaration of the function
2. Definition of the function
3. Calling the function

declaration and definition can be done in any order.

-> In what scenarios we can use 4 types of functions?

1. without arguments and without return type
-> when we want to print something on the screen or when we want to perform some task which does not require any input from the user and does not return any value to the user.

2. without arguments and with return type
-> when we want to perform some task which does not require any input from the user but returns some value to the user.

3. with arguments and without return type 
-> when we want to perform some task which requires input from the user and does not return any value to the user.

4. with arguments and with return type
-> when we want to perform some task which requires input from the user and returns some value to the user.

here arguments are the inputs given by the user and return type is the output given by the function.

*/