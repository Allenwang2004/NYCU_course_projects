#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

class Block
{
    public:
        string id;
        int width;
        int height;
        bool isSoft;
        Block(string id, int width, int height, bool isSoft)  //constructor
        {
            this->id = id;  //this指標指向物件本身 所以將id指向id
            this->width = width;
            this->height = height;
            this->isSoft = isSoft;
        }
};

bool compare(Block a, Block b)
{
    return a.id < b.id;
}

int main(int argc, char *argv[])
{
    ifstream inFile;
    inFile.open(argv[1]);
    ofstream outFile;
    outFile.open(argv[2]);
    double lowerBound, upperBound;
    inFile >> lowerBound >> upperBound;
    vector<Block> blocks; //建立一個vector存放類型為Block的物件，blocks為vector的名稱，也可以寫成Blocks blocks[]
    string line;
    while (getline(inFile, line))  //讀取檔案中的每一行
    {
        if (line.empty())
            continue;
        stringstream ss(line); //將line轉換成stringstream
        string id;
        int width, height;
        char c;
        ss >> id >> width >> height; 
        if (ss >> c)  //如果ss中還有字元，代表這個block是soft block
        {
            blocks.push_back(Block(id, width, height, true));
        }
        else
        {
            blocks.push_back(Block(id, width, height, false));
        }
    }
    sort(blocks.begin(), blocks.end(), compare);  //將blocks中的物件依照id排序
    //現在已經排序好了
    for (int i = 1; i < blocks.size(); i++)
    {
        if (blocks[i].isSoft)
        {
            double softBlockRatioLowerBound = lowerBound;
            double softBlockRatioUpperBound = upperBound;
            int sum = blocks[i].width * blocks[i].height;
            vector<pair<int, int>> pairs;
            for (int j = 1; j <= sum; j++)
            {
                if (sum % j == 0)
                {
                    int k = sum / j;
                    double ratio = (double)j / k;
                    if (ratio >= softBlockRatioLowerBound && ratio <= softBlockRatioUpperBound)
                    {
                        pairs.push_back(make_pair(j, k));
                    }
                }
            }
            sort(pairs.begin(), pairs.end());
            pairs.erase(unique(pairs.begin(), pairs.end()), pairs.end()); //刪除重複的pair
            outFile << blocks[i].id << " ";
            for (int j = 0; j < pairs.size(); j++)
            {
                outFile << "{" << pairs[j].first << "," << pairs[j].second << "} ";
            }
            outFile << endl;
        }
        else
        {
            if(blocks[i].width!=blocks[i].height)
            {
                if(blocks[i].width>blocks[i].height)
                {
                    outFile << blocks[i].id << " {" << blocks[i].height << "," << blocks[i].width << "} ";
                    outFile << "{" << blocks[i].width << "," << blocks[i].height << "}";
                    outFile << endl;
                }
                else
                {
                    outFile << blocks[i].id << " {" << blocks[i].width << "," << blocks[i].height << "} ";
                    outFile << "{" << blocks[i].height << "," << blocks[i].width << "}";
                    outFile << endl;
                }
            }
            else
            {
                outFile << blocks[i].id << " {" << blocks[i].width << "," << blocks[i].height << "} ";
                outFile << endl;
            }
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}

