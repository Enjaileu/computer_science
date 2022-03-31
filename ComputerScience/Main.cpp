#include <iostream>
#include "Factorial.h"
#include "Unique.h"
#include "LinkedList.h"
#include "Sort.h"
using namespace std;

int main() {

    vector<int> values{ 18,  15, 10, 5, 85, -5,  -78, 465,  -89, 5, 12, 63 };
    LinkedList list{ values };
    cout << "Liste initiale : " << endl;
    list.display();
    cout << endl;
    cout << "Bubble sort :" << endl;
    Sort::bubbleSort(list);
    list.display();
    cout << endl;
    cout << "Mix :" << endl;
    Sort::mixValues(list);
    list.display();
    cout << endl;
    cout << "Selection Sort :" << endl;
    Sort::selectionSort(list);
    list.display();
    cout << endl;
    cout << "Mix :" << endl;
    Sort::mixValues(list);
    list.display();
    cout << endl;
    cout << "Quick sort" << endl;
    Sort::quickSort(list);
    list.display();
    cout << endl;
    cout << "Mix :" << endl;
    Sort::mixValues(list);
    list.display();
    cout << endl;
    cout << "Merge Sort :" << endl;
    Sort::mergeSort(list);
    list.display();
    cout << endl;
    cout << "Clear la liste :";
    list.clear();
    list.display();

    return 0;
}