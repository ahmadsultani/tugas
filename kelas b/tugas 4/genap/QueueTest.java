import java.util.Scanner;
public class QueueTest {
    public static void main(String[] args) {
        LinkedQueue aq = new LinkedQueue();
        Scanner scan = new Scanner(System.in);
        System.out.print("Nama saya: ");
        String name = scan.nextLine();
        int countSpace = 0;
        int length = name.length();

        System.out.println("Memasukkan setiap karakter tanpa spasi ke antrian");
        for (int i = 0; i < length; i++) {
            if (name.charAt(i) == ' ') {
                countSpace++;
                continue;
            }
            aq.enqueue(name.charAt(i));
            System.out.print("+ Masuk ke antrian: " + name.charAt(i));
            System.out.print(" Yang paling depan: "+aq.peek());
            System.out.println(" Jumlah antrian: "+aq.size());
        }

        System.out.println("\nMengeluarkan setiap karakter dari antrian");
        for (int i = 0; i < length - countSpace; i++) {
            System.out.print("- Yang dilayani: "+aq.dequeue());
            System.out.println(" Jumlah antrian: "+aq.size());
        }
    }
}
