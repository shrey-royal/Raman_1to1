public class DoubleLL {
    private Node head;
    private Node tail;
    private int size;

    //Node class
    private class Node {
        int data;
        Node prev;
        Node next;

        Node(int data) {
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }

    //constructor of Main Class
    DoubleLL() {
        head = null;
        tail = null;
        size=0;
    }

    public void insertAtFront(int data) {
        Node newNode = new Node(data);
        if(head == null) {
            head = newNode;
            tail = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        size++;
    }

    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if(tail == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
        size++;
    }

    public void insertAfterNode(Node prevNode, int data) {
        if(prevNode == null) {
            System.out.println("Previous node cannot be null.");
            return;
        }
        Node newNode = new Node(data);
        newNode.next = prevNode.next;
        newNode.prev = prevNode;
        if(prevNode.next != null)
            prevNode.next.prev = newNode;
        else
            tail = newNode;
        prevNode.next = newNode;
        size++;
    }

    public void insertBeforeNode(Node nextNode, int data) {
        //
    }

    public void insertAtIndex(int index, int data) {
        //
    }

    public void deleteFromFront() {
        if(head == null) {
            System.out.println("List is Empty!");
            return;
        }

        if(head == tail) {
            head = null;
            tail = null;
        } else {
            head = head.next;
            head.prev = null;
        }
        size--;
    }

    public void deleteFromEnd() {
        if(head == null) {
            System.out.println("List is Empty!");
            return;
        }

        if(head == tail) {
            head = null;
            tail = null;
        } else {
            tail = tail.prev;
            tail.next = null;
        }
        size--;
    }

    public void deleteNode(Node node) {
        //
    }

    public void deleteAtIndex(int index) {
        //
    }

    public void traverseForward() {
        Node currentNode = head;
        while(currentNode != null) {
            System.out.print(currentNode.data + " ");
            currentNode = currentNode.next;
        }
        System.out.println();
    }

    public void traverseBackward() {
        Node currentNode = tail;
        while(currentNode != null) {
            System.out.print(currentNode.data + " ");
            currentNode = currentNode.prev;
        }
        System.out.println();
    }

    public boolean search(int data) {
        Node currentNode = head;
        while(currentNode != null) {
            if(currentNode.data == data) return true;
            currentNode = currentNode.next;
        }
        return false;
    }

    public int getLength() {
        return size;
    }

    public void reverseList() {
        Node temp = null;
        Node current = head;
        while(current != null) {
            temp = current.prev;
            current.prev = current.next;
            current.next = temp;
            current = current.prev;
        }
        if(temp != null)
            head = temp.prev;
    }



    public static void main(String[] args) {
        DoubleLL dll = new DoubleLL();

        //insert
        dll.insertAtEnd(10);
        dll.insertAtFront(5);
        dll.insertAfterNode(dll.head.next, 8);

        //displaying the list
        System.out.println("Doubly Linked List: ");
        dll.traverseForward();
        dll.traverseBackward();

        //search
        int searchKey = 8;
        System.out.println("Is " + searchKey + " present in the list? " + dll.search(searchKey));

        //reverse the list
        dll.reverseList();
        System.out.println("DLL reversed: ");
        dll.traverseForward();
    }
}