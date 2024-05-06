#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int countWords(const string& text)  
{
    stringstream ss(text);
    string word;
    int count = 0;
    while (ss >> word)
    {
        count++;
    }
    return count;
}

void computeStatistics(const string& inputFileName, const string& outputFileName) 
{
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) 
    {
        cout << "Error opening the file " << inputFileName << ". Please check the filename and try again." << endl;
        return;
    }

    int totalOccurrences = 0;
    int totalNonWhitespace = 0;
    int totalLetterOccurrences = 0;

    char ch;
    string fileContent;
    while (inputFile.get(ch)) 
    {
        totalOccurrences++;
        fileContent += ch;
        if (!isspace(ch)) 
        {
            totalNonWhitespace++;
            if (isalpha(ch)) 
            {
                totalLetterOccurrences++;
            }
        }
    }

    inputFile.close();

    int totalWords = countWords(fileContent);

    ofstream outputFile(outputFileName);
    if (outputFile.is_open()) 
    {
        outputFile << "Total number of words: " << totalWords << endl;
        outputFile << "Total number of characters: " << totalOccurrences << endl;
        outputFile << "Total number of non-whitespace characters: " << totalNonWhitespace << endl;
        outputFile << "Total number of letters: " << totalLetterOccurrences << endl;
        outputFile.close();
    } 
    else 
    {
        cout << "Error opening the output file " << outputFileName << ". Please check the filename and try again." << endl;
    }

    cout << "Total number of words: " << totalWords << endl;
    cout << "Total number of characters: " << totalOccurrences << endl;
    cout << "Total number of non-whitespace characters: " << totalNonWhitespace << endl;
    cout << "Total number of letters: " << totalLetterOccurrences << endl<<endl;
}

int main() 
{
    string inputFileName, outputFileName;
    cout << "Please enter the filename: ";
    cin >> inputFileName;
    cout << "Please enter the output filename: ";
    cin >> outputFileName;
    computeStatistics(inputFileName, outputFileName);
    return 0;
}


