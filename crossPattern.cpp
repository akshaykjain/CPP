#include <iostream>
using namespace std;

int main ()
{
   int a,b,n;
   cout  << "Enter the value of n:" << endl;
   cin   >> n;
   
   for (a=0; a<n; a++)
   {
      for (b=0; b<n; b++)
      {
         if (a==0 || a==(n-1) || b==0 || b==(n-1) || a==b || b==(n-1)-a)
            cout << "*";
         else
            cout << " ";
      }
      cout << endl;
   }
   return 0;
}