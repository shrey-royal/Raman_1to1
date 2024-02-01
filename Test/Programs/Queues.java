import java.util.Scanner;

public class Queues {
    private static final int MAX_SIZE = 100;
    private static int[] queue = new int[MAX_SIZE];
    private static int front = -1;
    private static int rear = -1;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\n\nQueue Menu:");
            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Peekfront and Peekrear");
            System.out.println("4. Display");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter element to enqueue: ");
                    int element = scanner.nextInt();
                    enqueue(element);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    peek();
                    break;
                case 4:
                    display();
                    break;
                case 0:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        } while (choice != 0);
        scanner.close();
    }

    public static void enqueue(int data) {
        if(rear == MAX_SIZE - 1) {
            System.out.println("Queue is full. Cannot enqueue.");
        } else {
            if(front == -1) {
                front = 0;
            }
            rear++;
            queue[rear] = data;
            System.out.println(data + " enqueued to the queue.");
        }
    }

    private static void dequeue() {
        if(front == -1 || front > rear) {
            System.out.println("Queue is empty. Cannot dequeue.");
        } else {
            System.out.println("Element dequeued: " + queue[front]);
            front++;
        }
    }

    private static void peek() {
        if(front == -1 || front > rear) {
            System.out.println("Queue is empty. Cannot dequeue.");
        } else {
            System.out.println("Front Element: " + queue[front]);
            System.out.println("Rear Element: " + queue[rear]);
        }
    }

    private static void display() {
        if(front == -1 || front > rear) {
            System.out.println("Queue is empty.");
        } else {
            System.out.println("Queue element: ");
            for (int i = front; i <= rear; i++) {
                System.out.print(queue[i] + " ");
            }
            System.out.println();
        }
    }
}
