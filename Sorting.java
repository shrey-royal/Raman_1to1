public class Sorting {
    static void printArray(int arr[]) {
        System.out.print("Array["+arr.length+"] = { ");
        for (int i : arr) {
            System.out.print(i + ", ");
        }
        System.out.println(" }");
    }

    static void bubbleSort(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if(arr[j]>arr[j+1]) {
                    //swap
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    static void selectionSort(int[] arr) {
        int n = arr.length;

        //One by One move boundary of unsorted array
        for (int i = 0; i < n-1; i++) {
            //Find the minimum element in unsorted array
            int minIndex = i;
            for (int j = i+1; j < n; j++) {
                if(arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            //Swap the found minimum element with the first element
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }

    static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = (low-1);

        for (int j = low; j < high; j++) {
            if(arr[j] < pivot) {
                i++;

                //swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }

    static void quickSort(int[] arr, int low, int high) {
        if(low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi-1);  //left sub-array
            quickSort(arr, pi+1, high); //right sub-array
        }
    }

    public static void main(String[] args) {
        int[] array = {64, 34, 25, 12, 22, 11, 90};

        System.out.print("Array before sorting: ");
        printArray(array);

        // bubbleSort(array);
        // selectionSort(array);
        quickSort(array, 0, array.length-1);
        
        System.out.print("Array after sorting: ");
        printArray(array);
    }
}
