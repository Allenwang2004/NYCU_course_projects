#include <iostream>

using namespace std;

class WindInfo
{
    double speed;
    char direction;
}
int main()
{
    WindInfo datapoint[10]; // Array of 10 WindInfo objects
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter wind speed: ";
        cin >> datapoint[i].speed;
        cout << "Enter wind direction: ";
        cin >> datapoint[i].direction;
    }
}
