#include "money.h"

Money Money::percent(int percent){
    Money m(0, 0);
    m.allCents = allCents * percent / 100;
    return m;
};

bool Money::operator<(const Money &m){
    return allCents < m.allCents;
};

bool Money::operator<=(const Money &m){
    return allCents <= m.allCents;
};

bool Money::operator>(const Money &m){
    return allCents > m.allCents;
};

bool Money::operator>=(const Money &m){
    return allCents >= m.allCents;
};