#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
using namespace std;

const string MAKAR  = "Makar Alexeevich";
const string MAKAR_fName  = "Makar";
const string MAKAR_lName  = "Alexeevich";
const string JOSEPH = "Joseph Bazdeev";
const string JOSEPH_fName = "Joseph";
const string JOSEPH_lName = "Bazdeev";
const string BORIS  = "Boris Drubetskoy";
const string BORIS_fName  = "Boris";
const string BORIS_lName  = "Drubetskoy";
const string INPUT_FILE_NAME = "WarAndPeace.txt";
ifstream input;



int fileCheck()
{
	input.open(INPUT_FILE_NAME.c_str());
    if (input.fail())
    {
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
    }
	else
		return 1;
}



void printHeader()
{
	cout << "LINE" << setw(20) << "POSITION" << setw(20) << "NAME" << endl;
}



int findPosition()
{
	string line;
	int curLine = 0; 
	int lineNoB, lineNoM, lineNoJ;
	size_t posB, posM, posJ;
	
	while(getline(input, line)) 
	{
		curLine++;
		if (line.find(BORIS) != string::npos)
		{	
			size_t position = (line.find(BORIS) + 1);
			cout  << curLine << setw(15) << position << setw(25) <<  BORIS << endl;
		}
		
		if (line.find(BORIS_fName) != string::npos)
		{	
			posB = (line.find(BORIS_fName) + 1);
			if (posB == (line.length() - (BORIS_fName.length() - 1)));
			    lineNoB = curLine;
		}
		
		if (line.find(BORIS_lName) != string::npos)
		{	
			size_t position = (line.find(BORIS_lName) + 1);
			if (position == 1 && lineNoB == (curLine - 1)) 
			    cout << lineNoB << setw(15) << posB << setw(25) <<  BORIS << endl;
		}
		
		if (line.find(MAKAR) != string::npos) 
		{
			size_t position = (line.find(MAKAR) + 1);
			cout  << curLine << setw(15) << position << setw(25) <<  MAKAR << endl;
		}
		
		if (line.find(MAKAR_fName) != string::npos)
		{	
			
			posM = (line.find(MAKAR_fName) + 1);
			if (posM == (line.length()- (MAKAR_fName.length() - 1)))
			    lineNoM = curLine;
		}
		
		if (line.find(MAKAR_lName) != string::npos)
		{	
			size_t position = (line.find(MAKAR_lName) + 1);
			if (position == 1 && lineNoM == (curLine - 1)) 
				cout  << lineNoM << setw(15) << posM << setw(25) <<  MAKAR << endl;
		}
		
		if (line.find(JOSEPH) != string::npos)  
		{
			size_t position = (line.find(JOSEPH) + 1);
			cout  << curLine << setw(15) << position << setw(25) <<  JOSEPH << endl;
		}
		
	    if (line.find(JOSEPH_fName) != string::npos)
		{	
			posJ = (line.find(JOSEPH_fName) + 1);
			if (posJ == (line.length() - (JOSEPH_fName.length() - 1))) 
			    lineNoJ = curLine;
		}
		
		if (line.find(JOSEPH_lName) != string::npos)
		{	
			size_t position = (line.find(JOSEPH_lName) + 1);
			if (position==1 && lineNoJ == (curLine - 1)) 
			    cout  << lineNoJ << setw(15) << posJ << setw(25) <<  JOSEPH << endl;
		}
	}
	return 0;
}


int main()
{
	int check = fileCheck();
	printHeader();
	if (check==1)
		findPosition();
	return 0;
}