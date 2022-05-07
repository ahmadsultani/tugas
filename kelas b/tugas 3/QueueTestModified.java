import java.util.Scanner;

public class QueueTestModified {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Jumlah orang yang mau diantri = ");
        int N = input.nextInt();
        int stop, count = 0;
        ArrayQueue aq = new ArrayQueue(N);
        System.out.println();
        while (N >= 0) {
            if (N < 5) stop = N;
            else stop = 5;
            for (int i = 0; i < stop; i++) {
                aq.enqueue("Orang-"+(count+1));
                System.out.print("+ Masuk ke antrian: "+"Orang-"+(count+1));
                System.out.print(" Yang paling depan: "+aq.peek());
                System.out.println(" Jumlah antrian: "+aq.size());
                count++;
            }
            for (int i = 0; i < stop; i++) {
                System.out.print("- Yang dilayani: "+aq.dequeue());
                System.out.println(" Jumlah antrian: "+aq.size());
            }
            N = N - 5;
        }
    }
}
