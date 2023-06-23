// Gauss Seidel
// Ahmad Sultani Dayanullah

#include <iostream> // library untuk input dan output
#define endl "\n" // untuk mengganti \n dengan endl (performa lebih cepat)
using namespace std; // untuk menghilangkan penulisan std:: pada setiap fungsi

/**
 * @brief fungsi untuk mengecek apakah x1 sudah memenuhi toleransi error
 *
 * @param x1 array yang berisi nilai x saat ini
 * @param x0 array yang berisi nilai x sebelumnya
 * @param n jumlah elemen pada array
 * @param e toleransi error
 * @return true jika x1 sudah memenuhi toleransi error
 * @return false jika x1 belum memenuhi toleransi error
 */
bool isTolerated(double* x1, double* x0, int n, double e) {
  bool isTolerated = true; // variabel untuk mengecek apakah x1 sudah memenuhi toleransi error
  for (int i = 0; i < n; i++) { // iterasi untuk setiap elemen pada array
    // jika selisih x1 dan x0 dibagi x1 lebih besar dari toleransi error maka x1 belum memenuhi toleransi error
    if (abs((x1[i] - x0[i])/x1[i]) > e) {
      isTolerated = false; // set isTolerated menjadi false
      break; // hentikan iterasi karena sudah tidak memenuhi toleransi error
    }
  }
  return isTolerated;
}

/**
 * @brief fungsi untuk menyelesaikan persamaan linear dengan metode Gauss Seidel
 *
 * @param A matriks A yang berisi koefisien persamaan
 * @param b matriks b yang berisi hasil persamaan
 * @param x0 matriks x0 yang berisi nilai awal
 * @param n jumlah baris pada matriks A
 * @param e toleransi error
 * @param N jumlah iterasi maksimum
 * @return double* array yang berisi nilai x yang memenuhi persamaan
 */
double* gaussSeidel(double **A, double* b, double* x0, int n, double e, int N) {
  double* x1 = new double[n]; // array yang berisi nilai x saat ini

  // iterasi sebanyak N kali atau sampai x1 memenuhi toleransi error
  for (int iter = 1; iter <= N; iter++) {
    for (int i = 0; i < n; i++) { // iterasi untuk setiap baris pada matriks A
      // variabel untuk menyimpan jumlah hasil perkalian matriks L (Lower) dan U (Uppwer) dengan x
      double sumLx = 0, sumUx = 0;
      // iterasi untuk menghitung hasil penjumlahan perkalian matriks L dengan x
      for (int j = 0; j < i; j++) {
        // menghitung hasil perkalian elemen matriks L dengan x
        sumLx += A[i][j] * x1[j];
      }
      // iterasi untuk menghitung hasil penjumlahan perkalian matriks U dengan x
      for (int j = i + 1; j < n; j++) {
        // menghitung hasil perkalian elemen matriks U dengan x
        sumUx += A[i][j] * x0[j];
      }
      // menghitung nilai xi dengan persamaan solusi ke i - (sumLx + sumUx) / elemen Aii
      x1[i] = (b[i] - sumLx - sumUx) / A[i][i];
    }

    // tampilkan nilai x1 setiap iterasi
    cout << "Iterasi ke-" << iter << ": "; // menampilkan iterasi saat ini
    for (int i = 0; i < n-1; i++) {
      cout << x1[i] << ", "; // menampilkan nilai x1 dipisahkan dengan koma
    }
    cout << x1[n-1] << endl; // menampilkan nilai x1 terakhir

    // cek apakah x1 sudah memenuhi toleransi error
    // jika ya maka berhenti dan kembalikan nilai x1
    if (isTolerated(x1, x0, n, e)) {
      return x1;
    }

    // deep copy x1 ke x0
    copy(x1, x1+n, x0);
  }

  // jika iterasi sudah mencapai N tetapi x1 belum memenuhi toleransi error maka lempar exception
  throw "Tidak ada solusi";
}

int main() {
  int n; // dimensi matriks (jumlah baris)
  cout << "Masukkan jumlah baris (matriks persegi): ";
  cin >> n;

  // matriks A yang berisi koefisien persamaan
  double** A = new double*[n]; // new double*[n] untuk membuat array dari pointer yang memiliki n row
  cout << "\nMasukkan matriks A (Koefisien persamaan): " << endl;
  for (int i = 0; i < n; i++) { // iterasi untuk setiap row
    A[i] = new double[n]; // new double[n] untuk membuat array biasa untuk setiap row dengan n kolom
    for (int j = 0; j < n; j++) {
      cout << "A" << i+1 << j+1 << " = ";
      cin >> A[i][j]; // mengisi elemen matriks A dengan membaca input dari pengguna
    }
  }

  // matriks b yang berisi hasil persamaan
  double* b = new double[n]; // new double[n] untuk membuat array biasa dengan n kolom
  cout << "\nMasukkan matriks b (Solusi persamaan): " << endl;
  for (int i = 0; i < n; i++) { // iterasi untuk setiap kolom
    cout << "b" << i+1 << " = ";
    cin >> b[i]; // mengisi elemen matriks b dengan membaca input dari pengguna
  }

  cout << "\nMasukkan nilai awal mulai dari x2: " << endl;
  // matriks x yang berisi nilai awal
  double* x = new double[n]; // new double[n] untuk membuat array biasa dengan n kolom
  for (int i = 1; i < n; i++) { // iterasi untuk setiap kolom mulai dari kolom ke 2 (indeks 1)
    cout << "x" << i+1 << " = ";
    cin >> x[i]; // mengisi elemen matriks x dengan membaca input dari pengguna
  }

  double e; // toleransi error
  cout << "\nMasukkan toleransi error: ";
  cin >> e; // membaca input toleransi error dari pengguna

  int maxIteration; // jumlah iterasi maksimum
  cout << "\nMasukkan jumlah iterasi maksimum: ";
  cin >> maxIteration; // membaca input jumlah iterasi maksimum dari pengguna
  cout << endl;

  // blok try catch untuk menangkap exception jika ada error yang terjadi
  try {
    // memanggil fungsi gaussSeidel untuk menyelesaikan persamaan linear
    double* x1 = gaussSeidel(A, b, x, n, e, maxIteration);
    cout << "\nSolusi: " << endl;
    for (int i = 0; i < n; i++) { // iterasi untuk setiap elemen
      cout << "x" << i+1 << " = " << x1[i] << endl; // menampilkan nilai x1
    }
  } catch (const char* msg) { // menangkap exception yang didapat atau dilempar
    cerr << msg << endl; // menampilkan pesan error
  }

  cout << "\n";
  return 0;
}