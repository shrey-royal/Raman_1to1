public class DQueue {
    private static final int MAX_SIZE = 100;
    private int[] deque;
    private int front, rear, size;

    public DQueue() {
        deque = new int[MAX_SIZE];
        front = rear = -1;
        size=0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == MAX_SIZE;
    }

    public void insertFront(int data) {
        if(isFull()) {
            System.out.println("Deque is full, Cannot insert.");
            return;
        }
        if(front == -1) {
            front = rear = 0;
        } else if(front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        deque[front] = data;
        size++;
    }

    public void insertRear(int data) {
        if(isFull()) {
            System.out.println("Deque is full, cannot insert.");
            return;
        }
        if(rear == -1) {
            front = rear = 0;
        } else if(rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = data;
        size++;
    }

    public int deleteFront() {
        if(isEmpty()) {
            System.out.println("Deque is empty, cannot delete.");
            return -1;
        }
        int data = deque[front];
        if(front == rear) {
            front = rear = -1;
        } else if(front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        size--;
        return data;
    }

    public int deleteRear() {
        if(isEmpty()) {
            System.out.println("Deque is empty, cannot delete.");
            return -1;
        }
        int data = deque[rear];
        if(front == rear) {
            front = rear = -1;
        } else if(rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
        size--;
        return data;
    }

    public int peekRear() {
        if(isEmpty()) {
            System.out.println("Deque is empty.");
            return -1;
        }
        return deque[rear];
    }

    public int peekFront() {
        if(isEmpty()) {
            System.out.println("Deque is empty.");
            return -1;
        }
        return deque[front];
    }

    public void displayDeque() {
        if(isEmpty()) {
            System.out.println("Deque is empty.");
            return;
        }
        int i = front;
        while(true) {
            System.out.print(deque[i] + " ");
            if(i == rear) break;
            i = (i+1) % MAX_SIZE;   //Circular Increment
        }
        System.out.println();
    }


    public static void main(String[] args) {
        DQueue deque = new DQueue();

        deque.insertFront(1);
        deque.insertRear(2);
        deque.insertFront(3);
        deque.insertRear(4);
        deque.displayDeque();

        System.out.println("Peek Front: " + deque.peekFront());
        System.out.println("Peek Rear: " + deque.peekRear());
        System.out.println("Delete Front: " + deque.deleteFront());
        System.out.println("Delete Rear: " + deque.deleteRear());
        deque.displayDeque();
        
    }
}
