#include <iostream>
using namespace std;

class AccountNumber
{
    int *account; //pointer to an array of type int
    int size;
    public:
        AccountNumber(int *arr, int s)  //constructor
        {
            account = new int[s];
            size = s;
            for (int i = 0; i < s; i++)
            {
                account[i] = arr[i];
            }
        }
        void display()
        {
            for (int i = 0; i < size; i++)
            {
                cout << account[i];
            }
        }
        void check()
        {
            int *temp = new int[size];
            for (int i = 0; i < size; i++)
            {
                temp[i] = account[i];
            }
            for (int i = size - 2; i >= 0; i -= 2)
            {
                temp[i] *= 2;
                if (temp[i] > 9)
                {
                    temp[i] -= 9;
                }
            }
            int sum = 0;
            for (int i = 0; i < size; i++)
            {
                sum += temp[i];
            }
            if (sum % 10 == 0)
            {
                cout << "Account number is valid." << endl;
            }
            else
            {
                cout << "Account number is not valid." << endl;
            }
            delete[] temp;
        }
        bool checkValid()
        {
            int *temp = new int[size];
            for (int i = 0; i < size; i++)
            {
                temp[i] = account[i];
            }
            for (int i = size - 2; i >= 0; i -= 2)
            {
                temp[i] *= 2;
                if (temp[i] > 9)
                {
                    temp[i] -= 9;
                }
            }
            int sum = 0;
            for (int i = 0; i < size; i++)
            {
                sum += temp[i];
            }
            if (sum % 10 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
            delete[] temp;
        }
        void leastSignificantDigit()
        {
            int *temp = new int[size + 1];
            for (int i = 0; i < size; i++)
            {
                temp[i] = account[i];
            }
            for (int i = size - 2; i >= 0; i -= 2)
            {
                temp[i] *= 2;
                if (temp[i] > 9)
                {
                    temp[i] -= 9;
                }
            }
            int sum = 0;
            for (int i = 0; i < size; i++)
            {
                sum += temp[i];
            }
            if (sum % 10 == 0)
            {
                cout << "Account number:";
                display();
                cout << endl;
            }
            else
            {
                for(int i=size-1;i>=0;i--)
                {
                    while(account[i]!=9)
                    {
                        account[i]++;
                        if(checkValid())
                        {
                            cout << "Correct Account Number:";
                            display();
                            return;
                        }
                    }
                
                }    
            }
            delete[] temp;
        }
};

int main()
{
    int size;
    cout << "Please enter the account's length:";
    cin >> size;
    int *arr = new int[size]; //pointer to an array of type int named arr
    cout << "Please enter your account number:";
    int num;
    cin >> num;
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i] = num % 10;
        num /= 10;
    }
    AccountNumber account(arr, size);
    account.check();
    account.leastSignificantDigit();
    delete[] arr;
    return 0;
}