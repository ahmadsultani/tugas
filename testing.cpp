#include <iostream>
using namespace std;

int main() {
    int A = 1000, i = 5, n = 3;
    float x = (100 + i)/100, sum = 0, F;
    for (int j = 0; j < n; j++) {
        sum = sum + x; 
        x = x * (100 + i)/100;
    }
    F = A*sum;
    cout << F;
    return 0;
}