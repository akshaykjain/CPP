#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

class RomanNumeral
{
public:
    RomanNumeral();
    RomanNumeral(string roman);
    RomanNumeral(int value);
	~RomanNumeral();
	
	friend RomanNumeral& operator -(RomanNumeral& Rn1, RomanNumeral& Rn2);
	friend RomanNumeral& operator +(RomanNumeral& Rn1, RomanNumeral& Rn2);
	friend RomanNumeral& operator *(RomanNumeral& Rn1, RomanNumeral& Rn2);
	friend RomanNumeral& operator /(RomanNumeral& Rn1, RomanNumeral& Rn2);
	friend bool operator ==(RomanNumeral& Rn1, RomanNumeral& Rn2);
	friend ostream& operator <<(ostream& outs, RomanNumeral& Rn);
	friend istream& operator >>(istream& ins, RomanNumeral& Rn);

	private:
    string roman;      // Roman numeral as a string
    int decimal;    // decimal value of the Roman numeral
	void toRoman(int decimal);    // calculate string from decimal value
    void	toDecimal(string &roman);  // calculate decimal value from string
	int value(char r);    //suppportive toDecimalfunction 
};

#endif /* ROMANNUMERAL_H_ */
