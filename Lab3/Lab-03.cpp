#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream inFile;
    inFile.open(argv[1]);
    typedef int* IntArrayPtr; // IntArrayPtr is a pointer to an int
    IntArrayPtr *m = new IntArrayPtr[5]; // m is a pointer to an array of pointers
    for(int i=0; i<5; i++)
    {
        m[i] = new int[5]; // m[i] is a pointer to an array of 20 integers
    }
    IntArrayPtr *p = new IntArrayPtr[25]; // p is a pointer to an array of pointers
    for(int i=0; i<25; i++)
    {
        p[i] = new int[2]; // p[i] is a pointer to an array of 2 integers
    }
    int monster[25][2];
    string move;
    int HP = 100;
    int EXP = 0;
    int level = 1;
    int position[2] = {0, 0}; // x, y
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            inFile >> m[i][j];
        }
    }
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            inFile >> p[i][j];
        }
    }
    int i = 0;
    while(inFile >> move)
    {
        i++;
        if (move == "U")
        {
            position[0]--;
        }
        if (move == "D")
        {
            position[0]++;
        }
        if (move == "L")
        {
            position[1]--;
        }
        if (move == "R")
        {
            position[1]++;
        }
        if (position[0] < 0)
        {
            position[0] = 0;
        }
        if (position[0] > 4)
        {
            position[0] = 4;
        }
        if (position[1] < 0)
        {
            position[1] = 0;
        }
        if (position[1] > 4)
        {
            position[1] = 4;
        }
        int monsterID = m[position[0]][position[1]]; //找到怪物的ID
        if (monsterID != -1) //如果怪物存在
        {
            HP -= p[monsterID][0];
            EXP += p[monsterID][1];
            if (HP <= 0)
            {
                cout << "DEAD";
                return 0;
            }
            if (EXP >= 100)
            {
                level++;
                HP = 100;
                EXP = 0;
            }
            cout << "step " << i <<":"<<endl;
            cout << "level:"<<level<<" "<< "hp:"<<HP<<" "<< "exp:"<<EXP<<endl;
            cout << endl;
        }
    }
    for(int i=0; i<5;i++)
    {
        delete [] m[i]; // delete the array pointed by m[i]
    }
    delete [] m; // delete the array pointed by m
    for(int i=0; i<25;i++)
    {
        delete [] p[i]; // delete the array pointed by m[i]
    }
    delete [] p; // delete the array pointed by m
}