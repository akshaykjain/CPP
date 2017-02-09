#include <iostream>
using namespace std;

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int i = 2, j = 5;

    swap(i, j);
    cout << i << " " << j << endl;
}