#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int arr[100],value,diff;
    cout << "Enter sequence of numbers, -1 when done: " << endl;
    
    for (int j=0; j<9; j++)
    {
        cin >> arr[j];
        if (arr[j] == -1)
            break;
    }  
    diff = abs(arr[0]-100);
    value = arr[0];
    
    for (int i=1; i<sizeof(arr); i++)
    {
        if (abs(arr[i]-100) < diff)
        {
            diff = abs(arr[i]-100);
            value = arr[i];
        } 
    }
    cout << value << " is the closest number to 100.";
}