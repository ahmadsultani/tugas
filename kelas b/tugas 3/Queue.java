public interface Queue {
    public int size();
    public boolean isFull();
    public boolean isEmpty();
    public Object peek() throws QueueEmptyException;
    public void enqueue(Object element) throws QueueFullException;
    public Object dequeue() throws QueueEmptyException;
}


