#include<stdio.h>
#include<stdlib.h>

void printArray(int*, int);
void bubbleSort(int*, int);
void selectionSort(int*, int);
void insertionSort(int*, int);
void quickSort(int*, int, int);
int partition(int*, int, int); //helper function for quick sort
void swap(int*, int*);  //helper function for swapping
void merge(int*, int, int, int);    //helper function for merge sort
void mergeSort(int*, int, int);

void main() {
    int choice, size;
    printf("\nEnter the size for the array: ");
    scanf("%d", &size);

    int arr[size];

    for(int i=0; i<size; i++) {
        arr[i] = rand() % 100;
    }

    printArray(arr, size);

    printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n5. Merge Sort\n6. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            bubbleSort(arr, size);
            printArray(arr, size);
            break;

        // case 2:
        //     selectionSort(arr, size);
        //     printArray(arr, size);
        //     break;

        // case 3:
        //     insertionSort(arr, size);
        //     printArray(arr, size);
        //     break;

        // case 4:
        //     quickSort(arr, 0, size-1);
        //     printArray(arr, size);
        //     break;

        // case 5:
        //     mergeSort(arr, 0, size-1);
        //     printArray(arr, size);
        //     break;

        case 6:
            exit(0);

        default:
            printf("\nInvalid choice\n");
            break;
    }//end switch
}//end main

void printArray(int* arr, int size) {
    printf("\narr[%d] = { ", size);
    for(int i=0; i<size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b }\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {    //size-i-1 because the last element is already sorted
            if(arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
        }
    }
}