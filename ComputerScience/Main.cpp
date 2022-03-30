#include <iostream>
#include "Factorial.h"
#include "Unique.h"
#include "LinkedList.h"
#include "Sort.h"
using namespace std;

int main() {

    vector<int> values{ 16, 18, 8, 15, 17, 10, 19, 5, 10 };
    LinkedList list{ values };
    list.display();
    cout << endl;
    Sort::quickSort(list);
    list.display();

    return 0;
}