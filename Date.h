#ifndef DATE_H
#define DATE_H

class Date
{
public:
    Date();
    Date(int d, int m, int y);

    virtual void print();
    virtual void nextDate();
    virtual bool isBefore(Date date);

    int getDay();
    int getMonth();
    int getYear();

protected:
    int day, month, year;

    void resetDayMonth();
    void newYear();

    bool is30();
    bool is31();
    bool isFerbuary();
};

class DatewithTime : public Date
{
public:
    DatewithTime();
    DatewithTime(int s, int mi, int h, int d, int m, int y);

    void print();
    void nextDate();
    bool isBefore(DatewithTime datewtime);
private:
    int hour, minute, second;
};

#endif // DATE_H
