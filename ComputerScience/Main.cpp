#include <iostream>
#include "Factorial.h"
#include "Unique.h"
#include "LinkedList.h"
#include "Sort.h"
using namespace std;

int main() {

    vector<int> values{ 95, 23, 8, 99, 2, 99, 86, 2 };
    LinkedList list{ values };
    list.display();
    Sort::bubbleSort(list);
    list.display();



    return 0;
}