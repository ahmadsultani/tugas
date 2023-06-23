#include <iostream>
using namespace std;

int* change(int* c, int r, int n){
  int* d = new int[r];
  for (int i = 0; i < r; i++) {
    d[i] = 0;
    while (n >= c[i]) {
      d[i] += 1;
      n -= c[i];
    }
  }
  return d;
}

int main() {
  int arr[] = {25, 10, 5, 1};
  int n = 67;
  int r = sizeof(arr)/sizeof(int);
  int* sol = change(arr, r, n);
  for (int i = 0; i < r; i++) {
    cout << sol[i] << " ";
  }
  cout << "\n";
  return 0;
}