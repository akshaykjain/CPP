#include <stdio.h>
#include "Sorter.h"
#include <iostream>
using namespace std;

int main()
{
    Sorter T1;
    T1.insertData(2);
    T1.insertData(3);
    T1.insertData(1);
    T1.insertData(7);
    T1.insertData(17);
    T1.insertData(9);
    T1.insertData(19);
    T1.insertData(25);
    T1.insertData(4);
    T1.display();
    
//    T1.bubbleSort();
//    T1.selectionSort();
//    T1.insertionSort();
//    T1.mergeSort();
//    T1.quickSort();
//    T1.heapsort();
    
    return 0;
}