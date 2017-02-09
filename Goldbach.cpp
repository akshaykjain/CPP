#include <iostream>
#include <cmath>
using namespace std;

int findPrimeNext(int, int);
int findPrimePrevious(int);
bool isPrime(int);
int p1 = 0, p2 = 0, n = 0;

int main()
{
	cout << "Primes:" << endl << endl;
	for(n = 1; n < 101; n++)
	{
		if(isPrime(n) && n != 1)
			cout << n << " ";
		else if (!isPrime(n) || n == 1)
			cout << ". ";
		if (n%10 == 0)
			cout << endl;
	}
	
	cout << endl << "Test of Goldbach's Conjecture:" << endl;
	for(n = 4; n < 101; n++)
	{
		if(n%2==0)
		{
			p1 = 2;
			p2 = findPrimePrevious(n);
			cout << endl << n << ": ";
			while (p1 <= p2) 
			{
				if ((p1 + p2) < n) 
					p1 = findPrimeNext(p1,n);
				else if ((p1 + p2) > n) 
					p2 = findPrimePrevious(p2);
				
				else 
				{
					cout << p1 << " " << p2 << endl;
					p1 = findPrimeNext(p1,n);
					p2 = findPrimePrevious(p2);
				}
			}
		}
	}
	return 0;
}

int findPrimePrevious(int a) 
{
	do
	{
		a--;
	}while (!isPrime(a) && (a > 2)) ;
	
	return a;
}

int findPrimeNext(int b, int num) 
{
	do
	{
		b++;
	}while (!isPrime(b) && (b < num)) ;
	return b;
}

bool isPrime(int n) 
{
	for (int i = 2; i < n; i++) 
	{
		if ((n%i) == 0 || n==1) 
			  return false;
	}
	return true; 
}
