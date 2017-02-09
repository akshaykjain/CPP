#include <iostream>
#include <string>
using namespace std;

string translate(int n);
string translatePart(int n);
string translateOnes(int n);
string translateTeens(int n);
string translateTens(int n);

int main()
{
    int number;
    do
    {
        cin >> number;

        if (number > 0)
        {
            cout << number << " : " << translate(number) << endl;
        }
    }
    while (number > 0);
}

string translate(int n)
{
    string words = "";
    int firstPart = n/1000;
    int secondPart = n%1000;

    if (firstPart > 0)
    {
        words += translatePart(firstPart) + " thousand ";
    }

    if (secondPart > 0) {
        words += translatePart(secondPart);
    }

    return words;
}

string translatePart(int n)
{
    string words = "";
    int hundreds = n/100;

    if (hundreds > 0)
    {
        words += translateOnes(hundreds) + " hundred ";
        n %= 100;
    }

    if ((n >= 11) && (n <= 19))
    {
        words += translateTeens(n);
    }
    else
    {
        int tens = n/10;
        words += translateTens(tens);
        n %= 10;

        if (n > 0)
        {
            if (tens >= 2)
            {
                words += "-";
            }
            words += translateOnes(n);
        }
    }

    return words;
}

string translateOnes(int n)
{
    switch (n)
    {
        case 0: return "";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
    }
}

string translateTeens(int n)
{
    switch (n)
    {
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
    }
}

string translateTens(int n)
{
    switch (n)
    {
        case 0: return "";
        case 1: return "ten";
        case 2: return "twenty";
        case 3: return "thirty";
        case 4: return "forty";
        case 5: return "fifty";
        case 6: return "sixty";
        case 7: return "seventy";
        case 8: return "eighty";
        case 9: return "ninety";
    }
}