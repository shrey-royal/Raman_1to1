import java.util.Scanner;

public class Searching {
    
    static int binarySearch(int arr[], int low, int high, int key) {
        if(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] == key) return mid;
            else if(arr[mid] > key) return binarySearch(arr, low, mid-1, key);
            else return binarySearch(arr, mid+1, high, key);
        }
        return -1;
    }
    
    
    public static void main(String[] args) {
        int arr[] = new int[5];
        
        System.out.println("Enter array elements: ");
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println(binarySearch(arr, 0, arr.length-1, 23));
    }
}
