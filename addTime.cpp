#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Hours: ";
    int hours;
    cin >> hours;
    while (hours > 23)
    {
        cout << "Invalid Input!" << endl;
        cout << "Enter Hours Again: ";
        cin >> hours;
    }

    cout << "Minutes: ";
    int minutes;
    cin >> minutes;
    while (minutes > 59)
    {
        cout << "Invalid Input!" << endl;
        cout << "Enter Minutes Again: ";
        cin >> minutes;
    }

    cout << "Minutes to add: ";
    int minutesToAdd;
    cin >> minutesToAdd;

    minutes = minutes + minutesToAdd;
    if (minutes > 59)
    {
        int b = minutes%60;
        int a = minutes/60;
        minutes = b;
        if (a > 23)
            a = a%24;
        hours = hours + a;
        if (hours > 23)
        	hours = hours-24;
    }
    
    else if(minutes < 0)
    {     
        hours--;
        if (minutes < -59)
        {
            int hoursToSubtract = minutes/60;
            int minutesToSubtract = minutes%60;
            hours += hoursToSubtract;
            while(hours < 0)
                hours = hours+24;
            minutes = minutesToSubtract+60;
                while (minutes==60)
                {
                    minutes=0;
                    hours++;
                }
        }
        else
            minutes = minutes+60;
    }
    cout << "Result : " << hours << ":" << minutes << endl;
}
