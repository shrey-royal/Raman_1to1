#include<stdio.h>
#include<stdlib.h>

void main() {
    // int a = 34, *p = &a;
    // p = &a;

    // printf("\nValue of a using a = %d", a);
    // printf("\nAddress of a using &a = %u", &a);
    // printf("\nValue of a using *p = %d", *p);
    // printf("\nAddress of a using p = %u", p);

    // char name[] = "This_is_an_Array", *arr = name;

    // printf("\nEnter your name: ");
    // scanf("%[^\n]s", arr);

    // printf("\nYour name is %s", arr);

    //pointer arithmetic
    // printf("%c", *(arr+4));

    //pointer to pointer
    // int a = 23, *p = &a, **ptr = &p;

    // printf("\nValue of a using a = %d", a);
    // printf("\nAddress of a using &a = %u", &a);
    // printf("\nValue of a using *p = %d", *p);
    // printf("\nAddress of a using p = %u", p);
    // printf("\nValue of a using *ptr = %d", **ptr);
    // printf("\nAddress of a using ptr = %u", *ptr);

    // int *p = NULL;
    // printf("%u", p);

    // int a = 34;
    // float b = 3.4;
    // char c = 's';
    // void *p;

    // p = &a;
    // printf("\na = %d", *(int *)p);
    // p = &b;
    // printf("\nb = %.2f", *(float *)p);
    // p = &c;
    // printf("\nc = %c", *(char *)p);

    // Dangling Pointers using dynamic memory allocation
    // 4 bytes of int memory block (64bit compiler)
    // allocated using malloc() during runtime
    int *ptr = (int *)malloc(sizeof(int)); // normal pointer

    *ptr = 10;

    // memory block deallocated using free() function
    free(ptr);


    // here ptr acts as a dangling pointer
    printf("%d", *ptr);
    // prints garbage value in the output console


}

/*
Pointers: used to store memory location/address of another variable and helps pointing to that variable to access it faster than the variable itself.

*p -> will point towards the value
p -> will get you the address stored inside the pointer

*/