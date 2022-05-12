public class ArrayStack implements Stack
{
	public static final int CAPACITY = 1000;
	
	private int capacity;
	private Object S[];
	private int top = -1;

	public ArrayStack()
	{
		this(CAPACITY);
	}

	public ArrayStack(int cap)
	{
		capacity = cap;
		S = new Object[capacity];
	}

	public int size()
	{
		return(top + 1);
	}

	public boolean isFull()
	{
		return(size() == capacity);
	}

	public boolean isEmpty()
	{
		return (top<0);
	}

	public Object peek() throws StackEmptyException
	{
		if (isEmpty())
			throw new StackEmptyException ("Stack is empty.");
		return S[top];
	}

	public void push(Object obj) throws StackFullException
	{
		if (isFull())
			throw new StackFullException ("Stack is full.");
		top = top + 1;
		S[top] = obj;
	}

	public Object pop() throws StackEmptyException
	{
		Object elem;
		if (isEmpty())
			throw new StackEmptyException ("NO MORE POP! Stack is empty.");
		elem = S[top];
		top = top - 1;
		return elem;
	}
}





