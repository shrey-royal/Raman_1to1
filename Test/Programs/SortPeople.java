
public class SortPeople {
    public String[] sortPeople(String[] names, int[] heights) {
        quickSort(names, heights, 0, heights.length-1);
        return names;
    }

    static void quickSort(String[] names, int[] heights, int low, int high) {
        if(low>=high) {
            return;
        }

        int start = low;
        int end = high;
        int mid = start + (end-start)/2;
        int pivot = heights[mid];
        while (start<=end) {
            while(heights[start]>pivot) {
                start++;
            }
            while(heights[end]<pivot) {
                end--;
            }

            if(start<=end) {
                swap(names, heights, start, end);
                start++;
                end--;
            }
        }
        quickSort(names, heights, low, end);
        quickSort(names, heights, start, high);
    }

    static void swap(String[] names, int[] heights, int start, int end) {
        int num = heights[start];
        heights[start] = heights[end];
        heights[end] = num;

        String name = names[start];
        names[start] = names[end];
        names[end] = name;
    }


    public static void main(String[] args) {
        String[] names = {"Mary", "John", "Emma"};
        int[] heights = {180, 165, 170};
    
        quickSort(names, heights, 0, heights.length-1);

        for (String name : names) {
            System.out.println(name);
        }
    
    }
}


/*

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.

*/