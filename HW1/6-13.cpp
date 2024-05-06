#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//計算字數
int countWords(const string& text)  //const string& text 代表傳入的參數是一個常數參考，這樣可以避免不必要的複製
{
    stringstream ss(text); //將text轉換成stringstream
    string word;
    int count = 0;
    while (ss >> word) //stringstream會自動以空白字元分割字串
    {
        count++;
    }
    return count;
}

int main() 
{
    string filename;
    cout << "Enter the name of the text file: ";
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening the file. Please check the filename and try again." << std::endl;
        return 1;
    }
    // Read the contents of the file
    stringstream buffer;
    buffer << file.rdbuf();
    string fileContent = buffer.str();
    file.close();
    int wordCount = countWords(fileContent);
    cout << "Number of words in the file: " << wordCount << std::endl;
    return 0;
}
