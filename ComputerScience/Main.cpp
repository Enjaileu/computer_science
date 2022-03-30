#include <iostream>
#include "Factorial.h"
#include "Unique.h"
#include "LinkedList.h"
using namespace std;

int main() {

    vector<int> values{ 95, 23, 8, 99 };
    LinkedList list{ values };
    list.display();

    return 0;
}