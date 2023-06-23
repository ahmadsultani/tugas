#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void insertionSort(int arr[], int n) {
  for (int j = 1; j < n; j++) {
    int i = 0;
    while (arr[j] > arr[i]) 
      i++;
    int m = arr[j];
    for (int k = 0; k <= j - i - 1; k++) {
      arr[j - k] = arr[j - k - 1];
    }
    arr[i] = m;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); //fast I/O
  int arr[] = {1,2,5,10,3,4,6,7,8,9};
  int n = sizeof(arr) / sizeof(arr[0]);
  insertionSort(arr, n);
  printArray(arr, n);


  int a = 0;
  int b = a + 2;
  while (b > a) {
    a++;
    b--;
  }
  cout << "\n";
  return 0;
}