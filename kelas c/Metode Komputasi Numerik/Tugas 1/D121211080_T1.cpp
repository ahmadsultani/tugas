#include <iostream>  // input output library
#include <cstring>   // for memset
#define endl '\n'    // new line
using namespace std; // standard namespace

/***
 * @brief fungsi untuk menghitung nilai v(t) dari persamaan v(t) = a0 + a1t + a2t^2
 * @param a array yang berisi nilai a0, a1, a2
 * @param t nilai t (waktu)
 * @return nilai v(t) dari persamaan v(t) = a0 + a1t + a2t^2
 */
double v(double *a, int t) {
  double sum = 0; // variabel untuk menyimpan hasil perhitungan
  double t_powered = 1; // variabel untuk menyimpan nilai t^i (nilai awal 1 karena t^0 = 1)
  for (int i = 0; i <= 2; i++) {// loop sebanyak 3 kali (a0, a1, a2)
    sum += a[i] * t_powered; // menghitung nilai v(t) dari persamaan v(t) = a0 + a1t + a2t^2
    t_powered *= t; // menghitung t^i
  }
  return sum; // mengembalikan nilai v(t) (disimpan dalam sum)
}

/**
 * @brief fungsi decomposeMatrix untuk melakukan dekomposisi matriks
 * L dan U dilewatkan dari params untuk menghemat memori sekaligus
 * karena L dan U akan dideklarasikan secara lokal nantinya
 * @param A matriks yang akan didekomposisi
 * @param L matriks segitiga bawah hasil dekomposisi
 * @param U matriks segitiga atas hasil dekomposisi
 * @param n ukuran matriks
 * @return void
 */
void decomposeMatrix(double **A, double **L, double **U, int n) {
  // loop sebanyak n kali sebagai representasi baris
  for (int j = 0; j < n; j++) {
    // loop sebanyak n kali sebagai representasi kolom (untuk matriks U)
    for (int k = j; k < n; k++) {
      double sum = 0; // variabel untuk menyimpan hasil penjumlahan dari sigma
      // loop sebanyak i kali sebagai representasi sigma dalam persamaan
      for (int s = 0; s <= j-1; s++) {
        sum += (L[j][s] * U[s][k]);
      }
      // persamaan untuk menghitung nilai U[i][k]
      U[j][k] = A[j][k] - sum;
    }

    // loop sebanyak n kali sebagai representasi kolom (untuk matriks L)
    for (int k = j; k < n; k++) {
      if (j == k) {
        L[j][j] = 1; // nilai diagonal matriks L adalah 1
        continue; // lanjut iterasi
      }

      double sum = 0; // variabel untuk menyimpan hasil penjumlahan dari sigma
      // loop hingga nilai s = j-1 sebagai representasi sigma dalam persamaan
      for (int s = 0; s <= j-1; s++) {
        sum += (L[k][s] * U[s][j]); // sesuai dengan persamaan
      }
      L[k][j] = (A[k][j] - sum) / U[j][j];
    }
  }

  // mencetak hasil dekomposisi L
  cout << "L:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << L[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // mencetak hasil dekomposisi U
  cout << "U:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << U[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

/**
 * @brief fungsi untuk menghitung nilai x dengan menggunakan metode Doolittle
 * @param A matriks yang akan dihitung
 * @param n ukuran matriks
 * @param sol array yang berisi solusi dari persamaan yang ditentukan
 * @return double* 
 */
double *doolittle(double **A, int n, double *sol) {
  double **L = new double *[n]; // matriks segitiga bawah, n baris
  double **U = new double *[n]; // matriks segitiga atas, n baris

  // inisialisasi matriks L dan U
  for (int i = 0; i < n; i++) {
    L[i] = new double[n]{0,0,0}; // setiap baris memiliki 3 kolom, diinialisasi dengan 0
    U[i] = new double[n]{0,0,0}; // setiap baris memiliki 3 kolom, diinialisasi dengan 0
  }

  // memanggil fungsi decomposeMatrix untuk mendapatkan matriks L dan U
  decomposeMatrix(A, L, U, n);

  double *y = new double[n]; // array untuk menyimpan nilai y
  double *x = new double[n]; // array untuk menyimpan nilai x

  // menghitung nilai y dengan menggunakan persamaan Ly = b
  for (int i = 0; i < n; i++) {
    double sum = 0; // variabel untuk menyimpan hasil penjumlahan sampai sebelum i = j
    for (int j = 0; j < i; j++) {
      sum += L[i][j] * y[j]; // mengalikan L[i][j] dengan y[j] dan menjumlahkannya
    }
    // solusi persamaan yang ditentukan - hasil penjumlahan kemudian dibagi dengan L[i][i], posisi saat ini
    y[i] = (sol[i] - sum) / L[i][i];
  }

  // mencetak nilai Y
  for (int i = 0; i < n; i++) {
    cout << "y" << i << " = " << y[i] << endl;
  }
  cout << endl;

  // menghitung nilai x dengan menggunakan persamaan Ux = y
  // berbeda dengan persamaan Ly = b, kali ini kita menghitung dari belakang
  // karena matriks yang digunakan adalah segitiga atas
  for (int i = n - 1; i >= 0; i--) {
    double sum = 0; // variabel untuk menyimpan hasil penjumlahan sampai sebelum i = j
    for (int j = n - 1; j > i; j--) { // loop dari belakang
      sum += U[i][j] * x[j]; // mengalikan U[i][j] dengan x[j] dan menjumlahkannya
    }
    // solusi persamaan yang ditentukan - hasil penjumlahan kemudian dibagi dengan U[i][i], posisi saat ini
    x[i] = (y[i] - sum) / U[i][i];
  }

  return x;
}

int main() {
  const int n = 3; // ukuran matriks

  double **A = new double *[n]; // inisialisasi matriks A, merepresentasikan n baris

  A[0] = new double[n]{1, 1, 1}; // koefisien persamaan 1
  A[1] = new double[n]{1, 2, 2}; // koefisien persamaan 2
  A[2] = new double[n]{1, 2, 3}; // koefisien persamaan 3

  double *sol = new double[n]{5, 6, 8}; // solusi dari persamaan

  // mencetak matriks A
  cout << "A: \n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // mencetak solusi
  cout << "sol: \n";
  for (int i = 0; i < n; i++) {
    cout << sol[i] << " ";
  }
  cout << "\n\n";

  // memanggil fungsi doolittle untuk mendapatkan nilai a
  double *a = doolittle(A, n, sol);

  // mencetak nilai a
  for (int i = 0; i < n; i++) {
    cout << "a" << i << " = " << a[i] << endl;
  }
  cout << endl;

  // mencetak v(t) dari 6 - 12
  for (int t = 6; t <= 12; t++) {
    cout << "v(" << t << ") = " << v(a, t) << endl; // mencari solusi dengan memanggil fungsi v
  }
  cout << endl;

  return 0;
}