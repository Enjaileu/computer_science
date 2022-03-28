#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num = 0;
    cout << "Enter a number : ";
    cin >> num;
    cout << "Factorial of entered number: " << factorial(num);
    return 0;
}