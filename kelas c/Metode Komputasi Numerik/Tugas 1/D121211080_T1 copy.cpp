#include <iostream>  // input output library
#include <cstring>   // for memset
using namespace std; // standard namespace

/***
 * Fungsi untuk menghitung nilai v(t) dari persamaan v(t) = a0 + a1t + a2t^2
 * @param a array yang berisi nilai a0, a1, a2
 * @param t nilai t (waktu)
 */
double v(double *a, int t) {
  double sum = 0;              // variabel untuk menyimpan hasil perhitungan
  for (int i = 0; i <= 2; i++) // loop sebanyak 3 kali (a0, a1, a2)
  {
    sum += a[i] * pow(t, i); // menghitung nilai v(t) dari persamaan v(t) = a0 + a1t + a2t^2
  }
  return sum; // mengembalikan nilai v(t) (disimpan dalam sum)
}

/***
 * Fnugsi decomposeMatrix untuk melakukan dekomposisi matriks
 * @param A matriks yang akan didekomposisi
 * @param L matriks segitiga bawah hasil dekomposisi
 * @param U matriks segitiga atas hasil dekomposisi
 * @param n ukuran matriks
 * L dan U dilewatkan dari params untuk menghemat memori sekaligus
 * karena L dan U akan dideklarasikan secara lokal nantinya
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
      double sum = 0; // variabel untuk menyimpan hasil penjumlahan dari sigma
      // loop hingga nilai sebagai representasi sigma dalam persamaan
      for (int s = 0; s <= j-1; j++) {
        sum += (L[j][s] * U[s][k]);
      }
      L[j][k] = (A[j][k] - sum) / U[k][k];
    }
  }
}

double *doolittle(double **A, int n, double *sol) // function to decompose the matrix into lower and upper triangular matrix
{
  double **L = new double *[n];
  double **U = new double *[n];

  for (int i = 0; i < n; i++)
  {
    L[i] = new double[n];
    U[i] = new double[n];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      U[i][j] = 0;
      L[i][j] = 0;
    }
  }

  decomposeMatrix(A, L, U, n);

  double *y = new double[n];
  double *x = new double[n];

  y[0] = sol[0] / L[0][0];
  for (int i = 1; i < n; i++)
  {
    double sum = 0;
    for (int j = 0; j < i; j++)
    {
      sum += L[i][j] * y[j];
    }
    y[i] = (sol[i] - sum) / L[i][i];
  }

  x[n - 1] = y[n - 1] / U[n - 1][n - 1];

  for (int i = n - 2; i >= 0; i--)
  {
    double sum = 0;
    for (int j = n - 1; j > i; j--)
    {
      sum += U[i][j] * x[j];
    }
    x[i] = (y[i] - sum) / U[i][i];
  }

  return x;
}

int main()
{
  const int n = 3;

  double **A = new double *[n];
  double *sol = new double[n];

  for (int i = 0; i < n; i++) {
    A[i] = new double[n];
  }

  cout << "\nEnter the elements of the coefficient: \n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "A[" << i << "][" << j << "]: ";
      cin >> A[i][j];
    }
  }

  cout << "\nEnter the elements of the solution: \n";
  for (int i = 0; i < n; i++)
  {
    cout << "sol[" << i << "]: ";
    cin >> sol[i];
  }

  double *a = doolittle(A, n, sol);

  cout << "\nSolution: \n";
  for (int i = 0; i < n; i++)
  {
    cout << "a" << i << " = " << a[i] << endl;
  }

  return 0;
}