#include <iostream>
#include "Factorial.h"
#include "Unique.h"
#include "LinkedList.h"
#include "Sort.h"
using namespace std;

int main() {

    vector<int> values{ 95, 8, -6, 2, 99, 86, 2, 23 };
    LinkedList list{ values };
    list.display();
    cout << endl;
    Sort::quickSort(list);
    list.display();


    return 0;
}