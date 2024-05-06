#include <bits/stdc++.h>

using namespace std;

#ifndef MONEY_H
#define MONEY_H

class Money{
    public:
        Money(int dollars, int cents){
                allCents = dollars * 100 + cents;
        };

        Money percent(int percent);
        bool operator<(const Money &m);
        bool operator<=(const Money &m);
        bool operator>(const Money &m);
        bool operator>=(const Money &m);

        float getMoney(){
            return float(allCents)/100;
        };

    private:
        long allCents;
};

#endif