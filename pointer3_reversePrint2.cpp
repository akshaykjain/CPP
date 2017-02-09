#include <iostream>

using namespace std;

int* reverse(int* start, int* end);

void print(int* a, int n)
{
   cout << "{";
   for (int i = 0; i < n; i++)
   {
      cout << " " << a[i];
      if (i < n - 1) cout << ",";
   }
   cout << " }" << endl;
}
   
int main()
{
   int a[] = { 5, 1, 4, 9, -4, 8, -9, 0 };
   print(reverse(a + 1, a + 5), 4);
   cout << "Expected: { -4, 9, 4, 1 }" << endl;
   
   int b[] = { 1, 4, 9, 0 };
   print(reverse(b + 1, b + 4), 3);
   cout << "Expected: { 0, 9, 4 }" << endl;

   int c[] = { 12, 13 };
   print(reverse(c, c + 1), 1);
   cout << "Expected: { 12 }" << endl;
   
   int d[] = { 14, 15 };
   print(reverse(d, d), 0);
   cout << "Expected: { }" << endl;
   
   return 0;
}

/**
   Given pointers start and end that point to the 
   first and past the last element of a segment inside
   an array, return a new array holding the reverse
   of the segment. 
*/
int* reverse(int* start, int* end)
{
	end--;
	int* temp = start;
//	int n = 0;
//	while (start!=end) 
//	{	
//		*start++;
//		n++;
//	}
	
//	int arr[n];
	int exchange;
//	for (int i = 0; i < n; i++)
	//{
		while(start<end)
		{
			exchange = *start;   
			*start = *end;
//			arr[i] = *start;
			*end = exchange;
			*start++;
			*end--;
		}
		if (end!=temp)
		*end--;
	//}
//		if (start == end)
//			arr[i] == *start;
//	}
//	int *ptr = &arr[0];
//		cout << *ptr;
		return end;
}
