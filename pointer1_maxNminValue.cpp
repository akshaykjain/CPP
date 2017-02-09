#include <iostream>
using namespace std;

void minmax(int* arr, int n, int* min, int* max);

int main()
{
	int a[] = { 1, 4, 9, -4, 8, 0 };
	int r1 = -999;
	int r2 = -999;
	minmax(a, sizeof(a) / sizeof(a[0]), &r1, &r2);
	cout << r1 << " " << r2 << endl;
	cout << "Expected: -4 9" << endl;

	int b[] = { 1 };
	r1 = -999;
	r2 = -999;
	minmax(b, sizeof(b) / sizeof(b[0]), &r1, &r2);
	cout << r1 << " " << r2 << endl;
	cout << "Expected: 1 1" << endl;

   int c[] = { 1, 4, 9, -4, 8, 0, 11, 23, -12 };
	r1 = -999;
	r2 = -999;
	minmax(c, sizeof(c) / sizeof(c[0]), &r1, &r2);
	cout << r1 << " " << r2 << endl;
	cout << "Expected: -12 23" << endl;
   
	return 0;
}

/*
   Compute the minimum and maximum value in a non-empty array.
   @param arr the array
   @param n the length of the array
   @param min a pointer to a variable holding the minimum
   @param max a pointer to a variable holding the minimum
*/
void minmax(int* arr, int n, int* min, int* max)
{
	int a = arr[0];
	int b = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < a)
			a = arr[i];
	}
	*min = a;
	
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > b)
			b = arr[i];
	}
	*max = b;
}
