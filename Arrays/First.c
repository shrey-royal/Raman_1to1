#include<stdio.h>
// #define SIZE 10

void rushingStuff(char topics[][10], int r, int c) {
    printf("topics[%d][%d] = { ", r, c);
    for(int i=0; i<r; i++) {
        printf("\"");
        for (int j = 0; j < c; j++) {
            printf("%c", topics[i][j]);
        }
        printf("\", ");
    }
    printf("\b\b }");
}

void main() {
    // int arr[10] = {0};    //declared
    // int size = sizeof(arr)/sizeof(arr[0]);

    // arr[0] = 1;
    // arr[1] = 2;
    // arr[2] = 435;
    // arr[6] = 234;

    // for(int i=0; i<size; i++) {
    //     printf("\nEnter arr[%d] = ", i);
    //     scanf("%d", &arr[i]);
    // }

    // printf("\narr[%d] = { ", size);
    // for(int i=0; i<size; i++) {
    //     printf("%d, ", arr[i]);
    // }
    // printf("\b\b }");

    // printf("%u", arr);

    char arr[][10] = {"C", "C++", "Java", "Python"};
    rushingStuff(arr, 4, 10);

}
/*
declaration: allocating the memory to the array
defination: assigning the values to the array
accessing the elements: getting specific elements/values by giving the index numbers

//declaration
datatype arrayname[size];

//definition
datatype arrname[] = {2, 1, 2, 4, 1, 23, 4};

arr[0] = 2;
arr[1] = 3;
arr[1] = 345;   //overwrite the previous one

*/