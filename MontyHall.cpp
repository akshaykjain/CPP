#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int SIMULATION_COUNT = 100;

void simulate(int sequence, int& win1, int& win2);
int hideCar();
int makeFirstChoice();
int openDoor(int firstChoiceDoor, int carBehindDoor);
int makeSecondChoice(int firstChoiceDoor, int openedDoor);
int randomDoor();
void printHeader();

void simulate(int sequence, int& win1, int& win2)
{   
    int carBehindDoor = hideCar();
    int firstChoiceDoor = makeFirstChoice();
    int openedDoor = openDoor(firstChoiceDoor, carBehindDoor);
    int secondChoiceDoor = makeSecondChoice (firstChoiceDoor, openedDoor);

    cout << sequence << setw(20) << carBehindDoor << setw(20) << firstChoiceDoor 
    << setw(30) << openedDoor << setw(30) << secondChoiceDoor;
    
    if (firstChoiceDoor==carBehindDoor)
    {
        win1++;
        cout << setw(30) << "yes" << endl;
    }
    if (secondChoiceDoor==carBehindDoor)
    {
        win2++;
        cout << setw(60) << "yes" << endl;
    }
}

int hideCar()
{
    int hide = randomDoor();
    return hide;
}

int makeFirstChoice()
{
    int fChoice = randomDoor();
    return fChoice;
}

int openDoor(int firstChoiceDoor, int carBehindDoor)
{
    int open = 0;
    do
    {
        open = randomDoor(); 
    }while (open==firstChoiceDoor || open==carBehindDoor);
}

int makeSecondChoice(int firstChoiceDoor, int openedDoor)
{
    int second = 0;
    do
    {
        second = randomDoor(); 
    }while (second==openedDoor || second==firstChoiceDoor);
}

int randomDoor()
{
   int rndmDoor = (1 + rand() % 3);
   return rndmDoor;
}

void printHeader()
{
    cout    << "#"<< setw(20) << "Car Here" << setw(20) << "First Choice"<< setw(20) << "Opened Door" << setw(20) 
            <<"Second Choice" << setw(20) << "Win First" << setw(20) << "Win Second" << endl;   
}

int main()
{
    int win1 = 0, win2 = 0;

    srand(time(NULL));
    printHeader();

    for (int i = 1; i <= SIMULATION_COUNT; i++) 
    simulate(i, win1, win2);

    cout << endl;
    cout << setw(4) << win1 << " wins if stay with the first choice" << endl;
    cout << setw(4) << win2 << " wins if switch to the second choice" << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << endl;
    cout << "Win ratio of switch over stay: ";
    cout << static_cast<double>(win2)/win1 << endl;
}