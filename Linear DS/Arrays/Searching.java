/*
Searching methods:
1. Linear Search
2. Binary Search

*/

import java.util.Scanner;

public class Searching {

    public static int linearSearch(int numbers[], int key) {
        for(int i=0; i<numbers.length; i++) {
            if(numbers[i] == key) {
                return i;   //key found
            }
        }
        return -1;  //Key not found
    }

    public static int binarySearch(int numbers[], int low, int high, int key) {
        if(low <= high) {
            int mid = low + (high - low) / 2;

            if(numbers[mid] == key) return mid;

            if(numbers[mid] > key) return binarySearch(numbers, low, mid-1, key);
            else return binarySearch(numbers, mid+1, high, key);
        }
        return -1;
    }


    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int key;

        System.out.println("Enter the number to search: ");
        Scanner sc = new Scanner(System.in);
        key = sc.nextInt();
        
        //Binary Search
        // int index = Searching.binarySearch(arr, 0, arr.length - 1, key);
        // if (index == -1) {
        //     System.out.println(key + " is not found in the array");
        // } else {
        //     System.out.println(key + " is found at index " + index);
        // }

        //Linear Search
        int linearIndex = Searching.linearSearch(arr, key);
        if (linearIndex == -1) {
            System.out.println(key + " is not found in the array");
        } else {
            System.out.println(key + " is found at index " + linearIndex);
        }
        sc.close();
    }
}

/*
Tasks :

1. Find the largest three elements in an array
2. Find the Missing Number
Given an array arr[] of size N-1 with integers in the range of [1, N], the task is to find the missing number from the first N integers.

Input: arr[] = {1, 2, 4, 6, 3, 7, 8}, N = 8
Output: 5
Explanation: The missing number between 1 to 8 is 5

Input: arr[] = {1, 2, 3, 5}, N = 5
Output: 4
Explanation: The missing number between 1 to 5 is 4


3. Find the first repeating element in an array of integers
4. Find the missing and repeating number

*/