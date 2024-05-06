#include "CNumpy.h"

CNumpy::CNumpy(const char *input_filename)
{
    ifstream file(input_filename);
    file >> row >> col;
    matrix = new int*[row];
    for(int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
        for(int j = 0; j < col; j++)
        {
            file >> matrix[i][j];
        }
    }
    file.close();
}

CNumpy::~CNumpy()
{
    for(int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int **CNumpy::getMatrix()const
{
    return matrix;
}

int CNumpy::getRow()const
{
    return row;
}

int CNumpy::getCol()const
{
    return col;
}

int CNumpy::min()const
{
    int min = matrix[0][0];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

int CNumpy::max()const
{
    int max = matrix[0][0];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

void CNumpy::argmin(int *idx1, int *idx2)
{
    int min = matrix[0][0];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(matrix[i][j] < min)
            {
                min = matrix[i][j];
                *idx1 = i;
                *idx2 = j;
            }
        }
    }
}

void CNumpy::argmax(int *idx1, int *idx2)
{
    int max = matrix[0][0];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(matrix[i][j] > max)
            {
                max = matrix[i][j];
                *idx1 = i;
                *idx2 = j;
            }
        }
    }
}

void CNumpy::concatenate(const CNumpy &c, int axis)
{
    // axis = 0 -> combine by row
    // axis = 1 -> combine by column
    if(axis == 0)
    {
        int **temp = new int*[row + c.getRow()];
        for(int i = 0; i < row + c.getRow(); i++)
        {
            temp[i] = new int[col];
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                temp[i][j] = matrix[i][j];
            }
        }
        for(int i = 0; i < c.getRow(); i++)
        {
            for(int j = 0; j < c.getCol(); j++)
            {
                temp[i + row][j] = c.getMatrix()[i][j];
            }
        }
        for(int i = 0; i < row; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = temp;
        row += c.getRow();
    }
    else if(axis == 1)
    {
        int **temp = new int*[row];
        for(int i = 0; i < row; i++)
        {
            temp[i] = new int[col + c.getCol()];
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                temp[i][j] = matrix[i][j];
            }
        }
        for(int i = 0; i < c.getRow(); i++)
        {
            for(int j = 0; j < c.getCol(); j++)
            {
                temp[i][j + col] = c.getMatrix()[i][j];
            }
        }
        for(int i = 0; i < row; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = temp;
        col += c.getCol();
    }
    else
    {
        cout << "Invalid axis" << endl;
    }
    
}
void CNumpy::render()
{
    for(int i =0;i < row; ++i)
    {
        for(int j=0;j<col; ++j)
        {
            if(matrix[i][j]>127)
            {
                cout << "@@";
            }
            else
            {
                cout << "__";
            }
        }
        cout << endl;
    }
}