#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void printHeader(ifstream& input);

class WidgetReport
{
public:
    WidgetReport(ifstream& input);  // constructor
	void print();

private:
    ifstream& input;  // reference to the input stream
	int state, plant, dept, empid, count;
	string fName, lName, name; 
	string line;
};

const string INPUT_FILE_NAME = "widgets.txt";

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME.c_str());
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
	
	printHeader(input);
	WidgetReport w(input); 	//object creation
	w.print(); 
    input.close();
    return 0;
}

//header printing logic
void printHeader(ifstream& input)
{
	string columnNames;
	string title1, title2, title3, title4, title5, title6;
	getline(input,columnNames);
	stringstream s1(columnNames);
	s1 >> title1 >> title2 >> title3 >> title4 >> title5 >> title6;
	cout << title1 << " " << title2 << " " << title3 << " " << title4 << " " << title6 << setw(10) << title5 << endl << endl;
}

// constructor definition
WidgetReport::WidgetReport(ifstream& input) : input(input)
{
	state	= 0;
	plant 	= 0;
	dept 	= 0;
	empid 	= 0;
	count 	= 0;
	name 	= "";
}

//print function definition
void WidgetReport :: print()
{
	int deptTotal, plantTotal, stateTotal;
	int deptPrev, plantPrev, statePrev, countPrev;
	int grandTotal;
	deptTotal = plantTotal = stateTotal = deptPrev = plantPrev = statePrev = countPrev = grandTotal = 0;
	while(getline(input,line))
	{
		stringstream ss(line);
		ss >> state >> plant >> dept >> empid >> fName >> lName >> count;
		name = fName + " " + lName;
		
		//logic to store count values
		if ((dept == deptPrev  && plant == plantPrev) || deptPrev == 0)
			deptTotal += count;
		if (plant == plantPrev || plantPrev == 0)
			plantTotal += count;
		if (state == statePrev || statePrev == 0)
			stateTotal += count;
		
		//department printing logic
		if (dept != deptPrev && deptPrev != 0)
		{
			cout << endl << setw(27) << deptTotal << "   TOTAL FOR DEPT " << deptPrev << " *" << endl;
			deptTotal = count;
		}
		if (dept != deptPrev && deptPrev != 0 && plant == plantPrev)
			cout << endl;
		if (dept == deptPrev  && plant != plantPrev && deptPrev != 0)
		{
			cout << endl << setw(27) << deptTotal << "   TOTAL FOR DEPT " << deptPrev << " *" << endl;
			deptTotal = count;
		}
		
		//plant printing logic
		if (plant != plantPrev && plantPrev !=0)
		{
			cout << setw(27) << plantTotal << "   TOTAL FOR PLANT " << plantPrev << " **" << endl;
			plantTotal = count;
		}
		if (plant != plantPrev && plantPrev != 0 && state == statePrev)
			cout << endl;
		if (state != statePrev && statePrev !=0)
		{
			cout << setw(27) << stateTotal << "   TOTAL FOR STATE " << statePrev << " ***" << endl << endl;
			stateTotal = count;
		}
		
		//state printing logic
		cout << state << setw(7) << plant << setw(6) << dept << setw(6) << empid << setw(6) << count << "   " << name << endl;
		
		deptPrev 	= dept;
		plantPrev 	= plant;
		statePrev	= state;
		statePrev	= state;
		countPrev 	= count;
		grandTotal	+= count;
	}
	
	//after getLine print logic
	cout << endl << setw(27) <<  deptTotal << "   TOTAL FOR DEPT " << deptPrev << " *" << endl;
	cout << setw(27) << plantTotal << "   TOTAL FOR PLANT " << plantPrev << " **" << endl;
	cout << setw(27) << stateTotal << "   TOTAL FOR STATE " << statePrev << " ***" << endl << endl ;
	cout << setw(27) << grandTotal << "   Grand TOTAL " << setw(10) << " ****";
}