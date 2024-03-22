#include <iostream>
#include "Date.h"

using namespace std;

void test1()
{
    int d1, m1, y1;
    cout << "Date" << endl;
    cout << "Enter day: ";
    cin >> d1;
    cout << "Enter month: ";
    cin >> m1;
    cout << "Enter year: ";
    cin >> y1;
    Date date1(d1, m1, y1);
    cout << "Entered date:" << endl;
    date1.print();

    cout << endl;

    int s2, mi2, h2, d2, m2, y2;
    cout << "Date with time" << endl;
    cout << "Enter second: ";
    cin >> s2;
    cout << "Enter minute: ";
    cin >> mi2;
    cout << "Enter hour: ";
    cin >> h2;
    cout << "Enter day: ";
    cin >> d2;
    cout << "Enter month: ";
    cin >> m2;
    cout << "Enter year: ";
    cin >> y2;
    DatewithTime date2(s2, mi2, h2, d2, m2, y2);
    cout << "Entered date:" << endl;
    date2.print();
    cout << endl;

    int s3, mi3, h3, d3, m3, y3;
    cout << "Another date with time" << endl;
    cout << "Enter second: ";
    cin >> s3;
    cout << "Enter minute: ";
    cin >> mi3;
    cout << "Enter hour: ";
    cin >> h3;
    cout << "Enter day: ";
    cin >> d3;
    cout << "Enter month: ";
    cin >> m3;
    cout << "Enter year: ";
    cin >> y3;
    DatewithTime date3(s3, mi3, h3, d3, m3, y3);
    cout << "Entered date:" << endl;
    date3.print();

    cout << endl;

    cout << "Is first date before second date? " << date1.isBefore(date2) << endl;
    cout << "Is second date before third date? " << date2.isBefore(date3) << endl;

    cout << endl;

    cout << "Date after first date: " << endl;
    date1.nextDate();
    date1.print();

    cout << "Second date + second: " << endl;
    date2.nextDate();
    date2.print();
}

int main()
{

    test1();

    return 0;
}
