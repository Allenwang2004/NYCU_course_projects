/*
What you need to design are 
1. Write a class called BasicTicket that stores a passenger's name, departure 
city, arrival city, flight number, and ticket price. 
2. Write a constructor to set the fields and include a method called get Price () 
which returns the price of the ticket. 
3. Write a derived class called PremiumTicket that inherits all the details from 
BasicTicket but also stores the passenger's seat number. 
4. Write a constructor which sets all the BasicTicket information and the seat 
number. The price for PremiumTickets is 10% more than the price of a 
BasicTicket.  
5. Write a function which redefines the get Price () method in PremiumTicket 
to return the price of the PremiumTicket by calling BasicTicket's getPrice ( ) 
method and multiplying the result by 10%. 
6. Write a driver program which creates a BasicTicket object and a Premium-
Ticket object, and prints out the price of both. 
7. Write a simple function to add the cost of all the tickets in the vector. 
1. input 第一行是乘客人數 
2. 輸入每位乘客的資訊 
3. 位置輸入0為BasicTicket 
4. Price顯示至小數點後兩位
input sample:
number of passenger
2
information
John NewYork LosAngeles 123 200.00 0
information 
Mary NewYork LosAngeles 124 300.00 1
output sample:
price of both tickets
200.00
330.00
total cost of all tickets : 530.00
要避開number of passenger這行
還有information這行　　
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BasicTicket
{
    protected:
        string name;
        string departcity;
        string arrivalcity;
        int number;
        float price;
    public:
        BasicTicket();
        BasicTicket(string n,string d,string a,int nu,float p);
        float getprice();
};

BasicTicket::BasicTicket()
{
    name = " ";
    departcity = " ";
    arrivalcity = " ";
    number = 0;
    price = 0.0;
}

BasicTicket::BasicTicket(string n,string d,string a,int nu,float p)
{
    name = n;
    departcity = d;
    arrivalcity = a;
    number = nu;
    price = p;
}

float BasicTicket::getprice()
{
    return price;
}

class PremiumTicket : public BasicTicket
{
    private:
        int seatnumber;
    public:
        PremiumTicket();
        PremiumTicket(string n,string d,string a,int nu,float p);
        float getprice();
};

PremiumTicket::PremiumTicket()
{
    seatnumber = 0;
}

PremiumTicket::PremiumTicket(string n,string d,string a,int nu,float p)
{
    name = n;
    departcity = d;
    arrivalcity = a;
    number = nu;
    price = p;
    seatnumber = 0;
}

float PremiumTicket::getprice()
{
    return price*1.1;
}

int main()
{
    int n;
    cin >> n;
    vector<BasicTicket*> ticket;
    for(int i = 0; i < n; i++)
    {
        string name,departcity,arrivalcity;
        int number;
        float price;
        int type;
        cin >> name >> departcity >> arrivalcity >> number >> price >> type;
        if(type == 0)
        {
            ticket.push_back(new BasicTicket(name,departcity,arrivalcity,number,price));
        }
        else
        {
            ticket.push_back(new PremiumTicket(name,departcity,arrivalcity,number,price));
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << ticket[i]->getprice() << endl;
    }
    float total = 0;
    for(int i = 0; i < n; i++)
    {
        total += ticket[i]->getprice();
    }
    cout << "total cost of all tickets : " << total << endl;
    return 0;
}


