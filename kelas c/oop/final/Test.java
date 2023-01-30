class Overload {
    void test(double a, double b) {
      System.out.println("Inside test(double, double): " + a + " " + b); 
    }
    void test(int a, int b, int c) {
      System.out.println("Inside test(int, int, int): " + a + " " + b + " " + c); 
    }
    void test(int a, int b) {
      System.out.println("Inside test(int, int): " + a + " " + b); 
    }
    int test(double a, double b) {
      System.out.println("Inside test(double, double): " + a + " " + b); 
      return 0;
    }
}

class OverloadDemo {
    public static void main(String args[]) {
        Overload ob = new Overload();
        double result;
        // call all versions of test()
        ob.test();
        ob.test(10);
        ob.test(10, 20);
        result = ob.test(123.25);
        System.out.println("Result of ob.test(123.25): " + result);
    }
}