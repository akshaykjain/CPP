#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

ifstream input;
int fileCheck();
void printHeader();
void createDatabase();
void display(string *names, int **arr, int count);
int fileCheck()
{
	const string INPUT_FILE_NAME = "students.txt";
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
	cout << "STUDENT SCORES for C++";
}

void createDatabase()
{
	string line;
	int count = 0;
	getline(input, line);
	
	stringstream s1(line);
	s1 >> line >> count;
	
	int **arr = new int*[count];
	string *names = new string[count];
	int scoreCount = 0;
	int x = 0;	//for string array manipulation
	int y = 0;	// for int array manipultaion
	
 	while(getline(input, line)) 
 	{
		string temp1;
		string temp2;
		for(unsigned int i = 0; i < line.size(); i++) 
		{	
			if (!isdigit(line[i])) 
				temp1 += line[i];
			if (!isalpha(line[i])) 
				temp2 += line[i];
		}
		names[x] = temp1;
		x++;
		stringstream s2(temp2);
		s2 >> scoreCount;
		
		if(y<count)
		{
			arr[y] = new int[scoreCount];
			for (int n = 0; n < scoreCount; n++)
			{
				s2 >> arr[y][n];
			}
			arr[y][scoreCount] = 0;
			y++;
		}
	}
	display(names, arr, count);	
	delete [] names;
	delete [] arr;
}

void display(string *names, int **arr, int count)
{
	int a = 0;
	for (int c = 0; c < count; c++)
	{
		int b = 0;
		cout << endl << endl << names[c] << endl;
		if (arr[a][0] == 0)
			cout << "(none)";
		else
		{
			while (arr[a][b] != 0)
			{
				cout << arr[a][b] << "  ";
				b++;
			}
		}
		a++;
	}	
}

int main()
{
	int check = fileCheck();
	if (check==1)
	{	
		printHeader();
		createDatabase();
	}
	return 0;
}