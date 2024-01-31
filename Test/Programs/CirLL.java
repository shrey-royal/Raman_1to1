class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}


public class CirLL {
    private Node head;

    public CirLL() {
        this.head = null;
    }

    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        if(head == null) {
            head = newNode;
            head.next = head;   //Circular reference
        } else {
            Node last = head;
            while(last.next != head) {
                last = last.next;
            }
            newNode.next = head;
            last.next = newNode;
            head = newNode;
        }
    }

    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if(head == null) {
            head = newNode;
            head.next = head;
        } else {
            Node last = head;
            while(last.next != head) {
                last = last.next;
            }
            last.next = newNode;
            newNode.next = head;
        }
    }

    public void insertAtPosition(int data, int position) {
        if(position <= 0) {
            System.out.println("Invalid position");
            return;
        }
        if(position == 1) {
            insertAtBeginning(data);
            return;
        }
        Node newNode = new Node(data);
        Node current = head;
        for (int i = 1; i < position-1 && current != null; i++) {
            current = current.next;
        }
        if(current == null) {
            System.out.println("Invalid position");
            return;
        }

        newNode.next = current.next;
        current.next = newNode;
    }

    public void printListFromBeginning() {
        if(head == null) {
            System.out.println("List is empty");
            return;
        }
        Node current = head;
        do{
            System.out.println(current.data + " ");
            current = current.next;
        } while(current != head);
        System.out.println();
    }

    public void printListFromEnd() {
        if(head == null) return;
        printFromEndRecursive(head);
    }

    private void printFromEndRecursive(Node node) {
        if(node.next == head) {
            System.out.println(node.data + " ");
            return;
        }
        printFromEndRecursive(node.next);
        System.out.println(node.data + " ");
    }

    public static void main(String[] args) {
        CirLL list = new CirLL();

        list.insertAtBeginning(1);
        list.insertAtEnd(3);
        list.insertAtPosition(2, 2);
        list.printListFromBeginning();
        list.printListFromEnd();
    }
}