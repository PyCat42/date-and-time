#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

// class Date

Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 2024;
}

bool Date::is31()
{
    return this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12;
}

bool Date::is30()
{
    return this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11;
}

bool Date::isFerbuary()
{
    return this->month == 2;
}

Date::Date(int d, int m, int y)
{
    this->year = y;
    this->month = (m >= 1 && m <= 12) ? m : 1;
    if(this->is30())
    {
        this->day = (d >= 1 && d <= 30) ? d : 1;
    }
    if(this->is31())
    {
        this->day = (d >= 1 && d <= 31) ? d : 1;
    }
    if(this->isFerbuary())
    {
        this->day = (d >= 1 && d <= 28) ? d : 1;
    }
}

void Date::print()
{
    cout << this->day << "." << this->month << "." << this->year << "." << endl;
}

void Date::resetDayMonth()
{
    this->day = 1;
    this->month++;
}

void Date::newYear()
{
    if(this->month == 12 && this->day == 31)
    {
        this->day = 1;
        this->month = 1;
        this->year++;
    }
    else
    {
        this->resetDayMonth();
    }
}

void Date::nextDate()
{
    if(this->is30() && this->day == 30)
    {
        this->resetDayMonth();
    }
    else if(this->is31() && this->day == 31)
    {
        this->newYear();
    }
    else if(this->isFerbuary() && this->day == 28)
    {
        this->resetDayMonth();
    }
    else
    {
        this->day++;
    }
}

bool Date::isBefore(Date date)
{
    if(this->year < date.year) return true;
    else if(this->year > date.year) return false;
    else
    {
        if(this->month < date.month) return true;
        else if(this->month > date.month) return false;
        else
        {
            if(this->day < date.day) return true;
            else return false;
        }
    }
}

int Date::getDay()
{
    return this->day;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getYear()
{
    return this->year;
}


// class DatewithTime

DatewithTime::DatewithTime() : Date()
{
    this->second = 0;
    this->minute = 0;
    this->hour = 0;
}

DatewithTime::DatewithTime(int s, int mi, int h, int d, int m, int y) : Date(d, m, y)
{
    this->second = (s >= 0 && s < 60) ? s : 0;
    this->minute = (mi >= 0 && mi < 60) ? mi : 0;
    this->hour = (h >= 0 && h < 24) ? h : 0;
}

void DatewithTime::print()
{
    string sec_str, min_str, h_str;
    sec_str = (this->second > 9) ? to_string(this->second) : ("0" + to_string(this->second));
    min_str = (this->minute > 9) ? to_string(this->minute) : ("0" + to_string(this->minute));
    h_str = (this->hour > 9) ? to_string(this->hour) : ("0" + to_string(this->hour));

    cout << h_str << ":" << min_str << ":" << sec_str << "  ";
    /*Date date = Date(this->day, this->month, this->year);
    date.print();*/
    this->Date::print();
}

void DatewithTime::nextDate()
{
    //Date date(this->day, this->month, this->year);

    this->second++;

    if(this->second == 60)
    {
        this->second = 0;
        this->minute++;
    }

    if(this->minute == 60)
    {
        this->second = 0;
        this->minute = 0;
        this->hour++;
    }

    if(this->hour == 24)
    {
        this->second = 0;
        this->minute = 0;
        this->hour = 0;

        this->Date::nextDate();
        /*this->day = date.getDay();
        this->month = date.getMonth();
        this->year = date.getYear();*/
    }
}

bool DatewithTime::isBefore(DatewithTime datewtime)
{
    Date date1(this->day, this->month, this->year);
    Date date2(datewtime.day, datewtime.month, datewtime.year);

    date1.isBefore(date2);

    if(this->hour < datewtime.hour) return true;
    else if(this->hour > datewtime.hour) return false;

    if(this->minute < datewtime.minute) return true;
    else if(this->minute > datewtime.minute) return false;

    if(this->second < datewtime.second) return true;
    else return false;
}
