import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}


public class LinkedList {
    private Node head;

    LinkedList() {
        head = null;
    }

    void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if(head == null) {
            head = newNode;
            return;
        }

        Node current = head;
        while(current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    void insertAtPosition(int data, int position) {
        if(position < 0) return;
        if(position == 0) {
            insertAtBeginning(data);
            return;
        }

        Node newNode = new Node(data);
        Node current = head;
        for (int i = 0; current != null && i < position - 2; i++) {
            current = current.next;
        }
        if(current == null) return;
        newNode.next = current.next;
        current.next = newNode;
    }

    boolean searchByValue(int value) {
        Node current = head;
        while(current != null) {
            if(current.data == value) return true;
            current = current.next;
        }
        return false;
    }

    int length() {
        int length = 0;
        Node current = head;
        while(current != null) {
            length++;
            current = current.next;
        }
        return length;
    }

    void reverse() {
        Node prev =null, current = head,  nextNode = null;
        while (current != null) {
            nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }

    void deleteAtBeginning() {
        if(head == null) return;
        head = head.next;
    }

    void deleteAtEnd() {
        if (head == null || head.next == null) {
            head = null;
            return;
        }
        Node current = head;
        while(current.next.next != null) {
            current = current.next;
        }
        current.next = null;
    }

    void deleteAtPosition(int position) {
        if(head == null || position < 0) return;
        if(position == 0) {
            head = head.next;
            return;
        }
        Node current = head;
        for (int i = 0; current != null && i < position - 1; i++) {
            current = current.next;
        }
        if(current == null || current.next == null) return;
        current.next = current.next.next;
    }

    void printListFromBeginning() {
        Node current = head;
        while(current != null) {
            System.out.print(current.data + "-> ");
            current = current.next;
        }
        System.out.println();
    }

    void printListFromEnd(Node node) {
        if(node == null) return;
        printListFromEnd(node.next);
        System.out.print(node.data + "-> ");
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList list = new LinkedList();
        int value;

        while (true) {
            // System.out.print("\033[H\033[2J");
            list.printListFromBeginning();
            System.out.println("\n\n1. Insert at beginning");
            System.out.println("2. Insert at end");
            System.out.println("3. Insert at position");
            System.out.println("4. Search by value");
            System.out.println("5. Length of the list");
            System.out.println("6. Reverse the list");
            System.out.println("7. Delete at beginning");
            System.out.println("8. Delete at end");
            System.out.println("9. Delete at position");
            System.out.println("10. Print list from beginning");
            System.out.println("11. Print list from end");
            System.out.println("12. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to insert at beginning: ");
                    value = sc.nextInt();
                    list.insertAtBeginning(value);
                    break;
                case 2:
                    System.out.print("Enter value to insert at end: ");
                    value = sc.nextInt();
                    list.insertAtEnd(value);
                    break;
                case 3:
                    System.out.print("Enter value to insert: ");
                    value = sc.nextInt();
                    System.out.print("Enter position: ");
                    int position = sc.nextInt();
                    list.insertAtPosition(value, position);
                    break;
                case 4:
                    System.out.print("Enter value to search: ");
                    int searchValue = sc.nextInt();
                    System.out.println("Value " + searchValue + " found: " + list.searchByValue(searchValue));
                    break;
                case 5:
                    System.out.println("Length of the list: " + list.length());
                    break;
                case 6:
                    list.reverse();
                    System.out.println("List reversed successfully.");
                    break;
                case 7:
                    list.deleteAtBeginning();
                    System.out.println("First element deleted successfully.");
                    break;
                case 8:
                    list.deleteAtEnd();
                    System.out.println("Last element deleted successfully.");
                    break;
                case 9:
                    System.out.print("Enter position to delete: ");
                    int deletePosition = sc.nextInt();
                    list.deleteAtPosition(deletePosition);
                    System.out.println("Element at position " + deletePosition + " deleted successfully.");
                    break;
                case 10:
                    System.out.println("List from beginning:");
                    list.printListFromBeginning();
                    break;
                case 11:
                    System.out.println("List from end:");
                    list.printListFromEnd(list.head);
                    System.out.println();
                    break;
                case 12:
                    System.out.println("Exiting...");
                    sc.close();
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        }
    }
}