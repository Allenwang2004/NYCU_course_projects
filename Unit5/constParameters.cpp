#include <iostream>

using namespace std;

class Day
{
    public:
        Day(int d);
        void setDay(int d);
        int getDay() const; //const成員函數 不能修改物件的資料成員
    private:
        int day;
};
Day::Day(int d)  //建構子
{
    day = d;
}
Day::setDay(int d) //設定day的值
{
    day = d;
}
int Day::getDay() const
{
    return day;
}
int main()
{
    Day d(3);
    cout << d.getDay() << endl; //輸出3
    d.setDay(4);
    cout << d.getDay() << endl; //輸出4
    return 0;
}