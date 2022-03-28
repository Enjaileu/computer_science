#include <iostream>
#include "Factorial.h"
#include "Unique.h"
using namespace std;

int main() {
    /*int num = 0;
    cout << "Enter a number : ";
    cin >> num;
    cout << "Factorial of entered number: " << factorial(num);*/

    string word = "";
    cout << "Enter a word : ";
    cin >> word;
    if (isUniqueOrganize(word)) {
        cout << "Each letter is unique in " << word << endl;
    }
    else { cout << "Some letters appears several time in " << word << endl; }
    return 0;
}