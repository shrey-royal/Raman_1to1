public class Stacc {
    private int maxSize;
    private int[] stackArray;
    private int top;

    public Stacc(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    void push(int value) {
        if(isFull()) {
            System.out.println("Stack is full. Can't push element...");
            return;
        }
        stackArray[++top] = value;
    }

    int pop() {
        if(isEmpty()) {
            System.out.println("Stack is empty. Can't pop element.");
            return -1;
        }
        return stackArray[top--];
    }

    int peek() {
        if(isEmpty()) {
            System.out.println("Stack is empty. Can't peek element.");
            return -1;
        }
        return stackArray[top];
    }

    boolean isEmpty() {
        return top == -1;
    }

    boolean isFull() {
        return top == maxSize - 1;
    }

    int size() {
        return top + 1;
    }

    void display() {
        if(isEmpty()) {
            System.out.println("Stack is Empty!");
            return;
        }
        System.out.println("Stack Elements: ");
        for (int i = 0; i <= top; i++) {
            System.out.println(stackArray[i] + " ");
        }
        System.out.println();
    }


    public static void main(String[] args) {
        Stacc s = new Stacc(5);

        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);

        s.display();

        System.out.println("pop: " + s.pop());
        System.out.println("top: " + s.peek());
        System.out.println("isEmpty: " + s.isEmpty());
        System.out.println("isFull: " + s.isFull());
        System.out.println("size: " + s.size());
    }
}
