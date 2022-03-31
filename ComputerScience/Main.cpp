#include <iostream>
#include "Factorial.h"
#include "Unique.h"
#include "LinkedList.h"
#include "Sort.h"
using namespace std;

int main() {

    vector<int> values{ 18,  15, 10, 5, 85, -5,  -78, 465,  -89, 5, 12, 63 };
    LinkedList list{ values };
    list.display();
    cout << endl;
    Sort::mergeSort(list);
    list.display();

    return 0;
}