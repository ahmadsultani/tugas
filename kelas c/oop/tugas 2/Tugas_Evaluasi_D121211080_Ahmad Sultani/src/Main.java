import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    GajiBulanan karyawan = new GajiBulanan();
    Scanner scan = new Scanner(System.in);

    System.out.print("Masukkan nama: ");
    karyawan.setNama(scan.nextLine());

    System.out.print("Masukkan gaji: ");
    karyawan.setGaji(scan.nextLong());

    System.out.println("\nNama: "+karyawan.getNama());
    System.out.println("Gaji: "+karyawan.getGaji());

    double gajiPajak = karyawan.getGaji()*0.9;
    System.out.println("Gaji Setelah Pajak: Rp."+gajiPajak);
  }
}
