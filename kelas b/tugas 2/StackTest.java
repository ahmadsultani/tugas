import java.util.Scanner;

public class StackTest
{
	public static void main(String[] args)
	{
		int N=45;
		ArrayStack myStack = new ArrayStack(N);

		System.out.println ("\nOperasi PUSH");

		for (int i = 0; i < N; i++)
		{
			myStack.push ("Piring-" +(i+1));
			System.out.print ("Item paling atas: " + myStack.peek());
			System.out.println (" Jumlah item di Stack: " + myStack.size());
		}

		System.out.println ("\n\nOperasi POP");
		for (int i = 0; i < N; i++)
		{
			System.out.println ("Item paling atas: " + myStack.peek());
			System.out.print ("Item yang dikeluarkan: " + myStack.pop());
			System.out.print (" Sisa item di Stack: " + myStack.size()+"  ");
		}
	}
}