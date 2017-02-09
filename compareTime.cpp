#include <iostream>
using namespace std;

int main()
{
    cout << "Enter Hours of first time" << endl;
    int hours1;
    cin >> hours1;
    while (hours1 > 23 || hours1 < 0)
    {
        cout << "Invalid Input!" << endl;
        cout << "Enter Hours Again: " << endl;
        cin >> hours1;
    }

    cout << "Enter Minutes of first time" << endl;
    int minutes1;
    cin >> minutes1;
    while (minutes1 > 59 || minutes1 < 0)
    {
        cout << "Invalid Input!" << endl;
        cout << "Enter Minutes Again: " << endl;
        cin >> minutes1;
    }

    cout << "Enter Hours of second time" << endl;
    int hours2;
    cin >> hours2;
    while (hours2 > 23 || hours2 < 0)
    {
        cout << "Invalid Input!" << endl;
        cout << "Enter Hours Again: " << endl;
        cin >> hours2;
    }

    cout << "Enter Minutes of second time" << endl;
    int minutes2;
    cin >> minutes2;
    while (minutes2 > 59 || minutes2 < 0)
    {
        cout << "Invalid Input!" << endl;
        cout << "Enter minutes Again: " << endl;
        cin >> minutes2;
    }

    if (hours1 < hours2)
        cout << "BEFORE";
    else if (hours1 > hours2)
        cout << "AFTER";
    else if (hours1 == hours2 && minutes1 == minutes2)
        cout << "SAME";
    else if (hours1 == hours2)
    {
        if (minutes1 < minutes2)
            cout << "BEFORE";
        else
            cout << "AFTER";
    }
}
