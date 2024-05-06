#include <iostream>

using namespace std;

class DayOfYear
{
    public:
        DayOfYear(int resetmonth,int resetday); //constructor
        ~DayOfYear(); //destructor
        void outoput();
        void set(int newMonth,int newDay);
    private:
        int month;
        int day;
};

void DayOfYear::outoput()
{
    cout << day << "/" << month << endl;
}

DayOfYear::DayOfYear(int resetmonth,int resetday)
{
    month = resetmonth;
    day = resetday;
}

DayOfYear::~DayOfYear()
{
    cout << "I am being destroyed" << endl;
}

void DayOfYear::set(int newMonth,int newDay)
{
    month = newMonth;
    day = newDay;
}

int main()
{
    DayOfYear my(11,10);
    my.outoput();
    my.set(12,25);
    my.outoput();
    my.~DayOfYear();
    my.outoput(); //雖然物件的生命週期結束，但是 my 物件的記憶體空間仍然存在，仍然可以訪問它
    return 0; //程式結束，my 物件的記憶體空間會被釋放 會呼叫析構函數 ~DayOfYear()
}