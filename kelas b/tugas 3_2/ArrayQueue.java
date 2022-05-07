public class ArrayQueue implements Queue {
    public static final int CAPACITY = 100;

    private int capacity;
    private Object S[];
    private int tail = -1;

    public ArrayQueue() {
        this(CAPACITY);
    }

    public ArrayQueue(int cap) {
        capacity = cap;
        S = new Object[capacity];
    }

    public int size() {
        return (tail + 1);
    }

    public boolean isFull() {
        return (size() == capacity);
    }

    public boolean isEmpty() {
        return (tail < 0);
    }

    public Object peek() throws QueueEmptyException {
        if (isEmpty()) {
            throw new QueueEmptyException("Queue is empty.");
        }
        return S[0];
    }

    public void enqueue(Object obj) throws QueueFullException {
        if (isFull()) {
            throw new QueueFullException("Queue is full.");
        }
        //masukkan antrian ke paling belakang
        tail++;
        S[tail] = obj;
    }

    public Object dequeue() throws QueueEmptyException {
        if (isEmpty()) {
            throw new QueueEmptyException("NO MORE DEQUEUE! Queue is empty.");
        }
        Object element = S[0];
        for (int i = 0; i <= tail-1; i++) {
            S[i] = S[i + 1];
        }
        tail--;
        return element;
    }
}