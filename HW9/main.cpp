#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BasicTicket
{
    friend class PremiumTicket;
private:
    string name;
    string departcity;
    string arrivalcity;
    int number;
    float price;
public:
    BasicTicket();
    BasicTicket(string n, string d, string a, int nu, float p);
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

BasicTicket::BasicTicket(string n, string d, string a, int nu, float p)
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
    PremiumTicket(string n, string d, string a, int nu, float p);
    float getprice();
};

PremiumTicket::PremiumTicket()
{
    seatnumber = 0;
}

PremiumTicket::PremiumTicket(string n, string d, string a, int nu, float p)
{
    name = n;
    departcity = d;
    arrivalcity = a;
    number = nu;
    price = p * 1.1;
}

float PremiumTicket::getprice()
{
    return BasicTicket::getprice();
}

int main()
{
    string line;
    int num;
    cin >> num;
    vector<float> prices;
    for (int i = 0; i <num; i++)

    for (int i = 0; i < num; i++)
    {
        string name, departcity, arrivalcity;
        int number;
        float price;
        int type;
        cin >> name >> departcity >> arrivalcity >> number >> price >> type;
        if (type == 0)
        {
            BasicTicket ticket(name, departcity, arrivalcity, number, price);
            prices.push_back(ticket.getprice());
        }
        else
        {
            PremiumTicket ticket(name, departcity, arrivalcity, number, price);
            prices.push_back(ticket.getprice());
        }
    }
    float total = 0;
    cout << "number of passenger"<<endl;
    for (int i = 0; i< num ; i++)
    {
        cout << "information" <<endl;
    }
    cout << "Price of both tickets : " << endl;
    for (int j = 0; j < num; j++)
    {
        cout << prices[j] << endl;
        total += prices[j];
    }
    cout << "Total cost of all tickets: " << total <<endl;

    return 0;
}