#include <iostream>
using namespace std;

char * deleteRepeats(char * letters, int& size)
{
    char *newletters = new char[size];
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        bool found = false;
        for (int k = 0; k < j; k++)
        {
            if(letters[i] == newletters[k])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            newletters[j++] = letters[i];
        }
    }
    newletters[j] = '\0';
    size = j; 
    cout << "The new size of string is " << size << endl;
    cout << "The string after deleteRepeats is " << newletters << endl;
    return newletters;
}

int main()
{
    cout << "Please enter the size of the string: ";
    int size;
    cin >> size;
    cout << "Please enter the string: ";
    char letters[size];
    cin >> letters;
    char *newletters = new char[size];
    newletters = deleteRepeats(letters, size);
    delete[] newletters;
    return 0;
}
