#include <iostream>
#include "Factorial.h"
#include "Unique.h"
#include "LinkedList.h"
#include "Sort.h"
using namespace std;

int main() {

    vector<int> values{ 95, 23, 8, -6, 2, 99, 86, 2 };
    LinkedList list{ values };
    list.display();
    cout << endl;
    Sort::selectionSort(list);
    list.display();


    return 0;
}