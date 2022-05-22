public interface Queue {
    public int size();
    public boolean isEmpty();
    public Object peek() throws QueueEmptyException;
    public void enqueue(Object element);
    public Object dequeue() throws QueueEmptyException;
}