#include <stdio.h>
#include <iostream>
#include "Sorter.h"
using namespace std;

Sorter::Sorter()
{
    length = 0;
}

void Sorter::makeEmpty()
{
    length = 0;
    cout << "The Array is Empty Now!!!" << endl;
}

bool Sorter::isFull() const
{
    if (length == 10)
        return true;
    else
        return false;
}

int Sorter::getLength() const
{
    return length;
}

void Sorter::insertData(int  value)
{
    arr[length] = value;
    length++;
    if (isFull())
    {
        return;
    }
}

void Sorter::removeData(int  value)
{
    for (int i = 0; i < length; i++)
    {
        if(arr[i] == value)
        {
            arr[i] = arr[length - 1];
            length--;
            cout << "Item '" << value << "' Deleted !!!" << endl;
            return;
        }
    }
    cout << "Item '" << value << "' Not Found !!!" << endl;
}

void Sorter::display()
{
    cout << endl << "Array :" << endl;
    cout << "Array Length : " << getLength() << endl;
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

void Sorter::bubbleSort()
{
    cout << endl << "Bubble Sort (Complexity : O(n^2))" << endl;
    for (int x = 0; x < length; x++)
    {
        for (int y = 0; y < (length-1); y++)
        {
            if(arr[y] > arr[y+1])
            {
                int temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }
    display();
}

void Sorter::selectionSort()
{
    cout << endl << "Selection Sort (Complexity : O(n^2))" << endl;
    for (int x = 0; x < (length-1); x++)
    {
        int min_index = x;
        for (int y = (x+1); y < length; y++)
        {
            if(arr[min_index] > arr[y])
                min_index = y;
        }
        int temp = arr[min_index];
        arr[min_index] = arr[x];
        arr[x] = temp;
    }
    display();
}

void Sorter::insertionSort()
{
    cout << endl << "Insertion Sort (Complexity : O(n^2)) " << endl;
    for(int x = 1; x < length; x++)
    {
        int value = arr[x];
        int hole = x;
        while (hole > 0 && arr[hole-1] > value)
        {
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }
    display();
}

void Sorter::mergeSort()
{
    m_sort(arr, length);
     cout << endl << "Merge Sort (Complexity : O(nlogn)) " << endl;
    display();
}

void Sorter::m_sort(int num[], int n)
{
    if (n < 2)
        return;
    int mid = n/2;
    int left[mid];
    int right[n-mid];
    for (int x = 0; x < mid; x++)
    {
        left[x] = num[x];
    }
    for (int y = mid; y < n; y++)
    {
        right[y-mid] = num[y];
    }
    int sizeL = sizeof(left) / sizeof(left[0]);
    int sizeR = sizeof(right) / sizeof(right[0]);
    m_sort(left, sizeL);
    m_sort(right, sizeR);
    merge(left, right, num, sizeL, sizeR);
}

void Sorter::merge(int left[], int right[], int num[], int nL, int nR)
 {
    int i, j, k = 0;
    
    while ((i < nL) && (j < nR))
    {
        if (left[i] <= right[j])
        {
            num[k] = left[i];
            i++;
        }
        else
        {
            num[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < nL)
    {
        num[k] = left[i];
        i++;
        k++;
    }
    
    while (j < nR)
    {
        num[k] = right[j];
        j++;
        k++;
    }
}

void Sorter::quickSort()
{
    q_sort(arr, 0, (length-1));
    cout << endl << "Quick Sort (Complexity : O(n^2)) " << endl;
    display();
}

void Sorter::q_sort(int num[], int start, int end)
{
    if (start < end)
    {
        int p_index = q_sortPartition(num, start, end);
        q_sort(num, start, (p_index-1));
        q_sort(num, (p_index+1), end);
    }
}

int Sorter::q_sortPartition(int num[], int start, int end)
{
    int pivot = num[end];
    int p_index = start;
    for (int x = start; x < end; x++)
    {
        if(num[x] <= pivot)
        {
            int y = num[x];
            num[x] = num[p_index];
            num[p_index] = y;
            p_index++;
        }
    }
    int m = num[end];
    num[end] = num[p_index];
    num[p_index] = m;
    return p_index;
}

void Sorter::heapsort()
{
    // Build heap (rearrange array)
    for (int i = length / 2 - 1; i >= 0; i--)
        heapify(arr, length, i);
 
    // One by one extract an element from heap
    for (int i = length-1; i >= 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    cout << endl << "Heap Sort (Complexity : O(nlogn)) " << endl;
    display();
}

void Sorter::heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}