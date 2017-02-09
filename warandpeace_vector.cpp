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
	const vector<string> v = {"Makar Alexeevich", "Makar", "Alexeevich" ,"Joseph Bazdeev", "Joseph", "Bazdeev", "Boris Drubetskoy", "Boris", "Drubetskoy"};	
	string line;
	int curLine = 0; 
	int lineNoB, lineNoM, lineNoJ;
	size_t posB, posM, posJ;
	
	while(getline(input, line)) 
	{
		curLine++;
		if (line.find(v[6]) != string::npos)
		{	
			size_t position = (line.find(v[7]) + 1);
			cout  << curLine << setw(15) << position << setw(25) <<  v[6] << endl;
		}
		
		if (line.find(v[7]) != string::npos)
		{	
			posB = (line.find(v[7]) + 1);
			if (posB == (line.length() - (v[7].length() - 1)));
			    lineNoB = curLine;
		}
		
		if (line.find(v[8]) != string::npos)
		{	
			size_t position = (line.find(v[8]) + 1);
			if (position == 1 && lineNoB == (curLine - 1)) 
			    cout << lineNoB << setw(15) << posB << setw(25) <<  v[6] << endl;
		}
		
		if (line.find(v[0]) != string::npos) 
		{
			size_t position = (line.find(v[0]) + 1);
			cout  << curLine << setw(15) << position << setw(25) <<  v[0] << endl;
		}
		
		if (line.find(v[1]) != string::npos)
		{	
			
			posM = (line.find(v[1]) + 1);
			if (posM == (line.length()- (v[1].length() - 1)))
			    lineNoM = curLine;
		}
		
		if (line.find(v[2]) != string::npos)
		{	
			size_t position = (line.find(v[2]) + 1);
			if (position == 1 && lineNoM == (curLine - 1)) 
				cout  << lineNoM << setw(15) << posM << setw(25) <<  v[0] << endl;
		}
		
		if (line.find(v[3]) != string::npos)  
		{
			size_t position = (line.find(v[3]) + 1);
			cout  << curLine << setw(15) << position << setw(25) <<  v[3] << endl;
		}
		
	    if (line.find(v[4]) != string::npos)
		{	
			posJ = (line.find(v[4]) + 1);
			if (posJ == (line.length() - (v[4].length() - 1))) 
			    lineNoJ = curLine;
		}
		
		if (line.find(v[5]) != string::npos)
		{	
			size_t position = (line.find(v[5]) + 1);
			if (position==1 && lineNoJ == (curLine - 1)) 
			    cout  << lineNoJ << setw(15) << posJ << setw(25) <<  v[3] << endl;
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