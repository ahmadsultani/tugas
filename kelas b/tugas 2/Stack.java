public interface Stack
{
	public int size();
	public boolean isFull();
	public boolean isEmpty();
	public Object peek() throws StackEmptyException;
	public void push (Object item) throws StackFullException;
	public Object pop() throws StackEmptyException;
}