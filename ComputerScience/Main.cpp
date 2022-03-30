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

    cout << list.at(0)->value << endl;
    cout << list.at(29)->value << endl;
    cout << list.at(4)->value << endl;
    cout << endl;

    list.remove();
    cout << "remove last item" << endl;
    list.display();

    cout << endl;
    cout << "remove index 1" << endl;
    list.remove(1);
    list.display();
    cout << endl;
    cout << "remove index 0" << endl;
    list.remove(0);
    list.display();
    list.remove(2);

    cout << endl;
    cout << "insert 23 at index 0" << endl;
    list.insert(23, 0);
    list.display();
    cout << endl;
    cout << "insert 43 at index 5" << endl;
    list.insert(43, 5);
    list.display();
    cout << endl;
    cout << "insert 12 at index 4" << endl;
    list.insert(12, 4);
    list.display();
    list.insert(5, 7);
    list.display();
    list.insert(90, -8);

    return 0;
}