#include <iostream>
#include "Factorial.h"
#include "Unique.h"
#include "LinkedList.h"
using namespace std;

int main() {
    /*int num = 0;
    cout << "Enter a number : ";
    cin >> num;
    cout << "Factorial of entered number: " << factorial(num);*/

   /* string word = "";
    cout << "Enter a word : ";
    cin >> word;
    if (isUniqueOrganize(word)) {
        cout << "Each letter is unique in " << word << endl;
    }
    else { cout << "Some letters appears several time in " << word << endl; }*/

    LinkedList list;

    list.display();
    cout << endl;
    list.add(9);
    list.add(5);
    list.add(8);
    list.add(45);
    list.add(1);
    list.display();
    cout << endl;

    cout << list.at(0).value << endl;
    cout << list.at(29).value << endl;
    cout << list.at(4).value << endl;

    return 0;
}