public class LinkedQueue implements Queue {
    private Node first;
    private Node last;
    private int count;

    public LinkedQueue() {
        first = null;
        last = null;    
        count = 0;
    }

    public int size() {
        return count;
    }

    public boolean isEmpty() {
        return (size() == 0);
    }

    public Object peek() throws QueueEmptyException {
        if (isEmpty()) {
            throw new QueueEmptyException("Queue is empty.");
        }
        return first.element;
    }

    public void enqueue(Object obj) {
        Node xNode = new Node(obj, null);
        if (isEmpty()) {
            first = xNode;
        } else {
            last.next = xNode;
        }
        last = xNode;
        count++;
    }

    public Object dequeue() throws QueueEmptyException {
        if (isEmpty()) {
            throw new QueueEmptyException("NO MORE DEQUEUE! Queue is empty.");
        }
        Object elem = first.element;
        first = first.next;
        if (first == null) {
            last = null;
        }
        count--;
        return elem;
    }
}