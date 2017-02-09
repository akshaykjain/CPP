#include "RomanNumeral.h"
using namespace std;

/**
 * Default constructor.
 */
RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{

}

 RomanNumeral::RomanNumeral(string roman) : roman(roman)
 {
	toDecimal(roman);
 }

 RomanNumeral::RomanNumeral(int decimal) : decimal(decimal)
 {
	toRoman(decimal); 
 }

RomanNumeral::~RomanNumeral()
{

}
 
 void RomanNumeral::toRoman(int decimal)
 {
	int x = decimal;
	string M[]	= {"","M","MM","MMM"};
    string C[]	= {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string X[]	= {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string I[]	= {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    roman 	= M[x/1000] + C[(x%1000)/100] + X[(x%100)/10] + I[(x%10)];
 }

 int RomanNumeral::value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}

void RomanNumeral::toDecimal(string &roman)
{
    int x = 0;
    for (unsigned int i=0; i<roman.length(); i++)
    {
        int a = value(roman[i]);
        if (i+1 < roman.length())
        {
            int b = value(roman[i+1]);
            if (a >= b)
            {
                x = x + a;
            }
            else
            {
                x = x + b - a;
                i++;
            }
        }
        else
        {
            x = x + a;
            i++;
        }
    }
    decimal = x;
}

ostream& operator <<(ostream& outs, RomanNumeral& Rn)
{
    outs << "[" << Rn.decimal << ":" << Rn.roman << "]";
    return outs;
}

istream& operator >>(istream& ins, RomanNumeral& Rn)
{
	string x;
	string y;
	ins >> x;
	Rn.toDecimal(x);
	Rn.roman = x;
	return ins;
}

RomanNumeral& operator -(RomanNumeral& Rn1, RomanNumeral& Rn2)
{
	int x = Rn1.decimal - Rn2.decimal;
	RomanNumeral* Rn = new RomanNumeral(x);
	return *Rn;
}

RomanNumeral& operator +(RomanNumeral& Rn1, RomanNumeral& Rn2)
{
	int x = Rn1.decimal + Rn2.decimal;
	RomanNumeral* Rn = new RomanNumeral(x);
	return *Rn;
}

RomanNumeral& operator /(RomanNumeral& Rn1, RomanNumeral& Rn2)
{
	int x = Rn1.decimal / Rn2.decimal;
	RomanNumeral* Rn = new RomanNumeral(x);
	return *Rn;
}

RomanNumeral& operator *(RomanNumeral& Rn1, RomanNumeral& Rn2)
{
	int x = Rn1.decimal * Rn2.decimal;
	RomanNumeral* Rn = new RomanNumeral(x);
	return *Rn;
}

bool operator ==(RomanNumeral& Rn1, RomanNumeral& Rn2)
{
	if (Rn1.decimal == Rn2.decimal)
		return true;
	else
		return false;
}