public class KaryawanMagang implements Karyawan, Mahasiswa {
  private String jabatan;
  private String nik;
  private String nama;
  private String universitas;

  public String getJabatan() {
    return jabatan;
  }

  public void setJabatan(String jabatan) {
    this.jabatan = jabatan;
  }

  public String getNik() {
    return nik;
  }

  public void setNik(String nik) {
    this.nik = nik;
  }

  public String getNama() {
    return nama;
  }

  public void setNama(String nama) {
    this.nama = nama;
  }

  public String getUniversitas() {
    return universitas;
  }

  public void setUniversitas(String universitas) {
    this.universitas = universitas;
  }
}
