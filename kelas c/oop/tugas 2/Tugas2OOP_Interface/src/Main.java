public class Main {
  public static void main(String[] args) {
    KaryawanMagang karyawan1 = new KaryawanMagang ( ) ;
    karyawan1.setJabatan( "Akuntan" );
    karyawan1.setNama("Budi") ;
    karyawan1.setNik("7370002909940001") ;
    System.out.println("Jabatan: "+karyawan1.getJabatan());
    System.out.println("Nama : "+karyawan1.getNama ( ) ) ;
    System.out.println("NIK: "+karyawan1.getNik ( ) ) ;
    System.out.println("warganegara : "+karyawan1.warganegara);
    karyawan1.setUniversitas("Universitas Hasanuddin");
    System.out.println( "Asal Universitas : "+karyawan1.getUniversitas()) ;
  }
}