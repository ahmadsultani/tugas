import java.util.Scanner;

public class KonversiSultani {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    System.out.println("Pilih 1 = konversi dari Fahrenheit ke Celcius");
    System.out.println("Pilih 2 = konversi dari Celcius ke Fahrenheit");
    String pilih = scan.nextLine();

    double suhu;

    scan.close();
  }
  public static void celciusToFahrenheit(double suhu) {
    double result = (suhu * 9 / 5) + 32;
    System.out.println(suhu+"°C"+" = "+result+"°F");
  }
  public static void fahrenheitToCelcius(double suhu) {
    double result = (suhu - 32) * 5 / 9;
    System.out.println(suhu+"°F"+" = "+result+"°C");
  }
}
