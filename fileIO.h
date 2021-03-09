#include< bits/stdc++.h>

using namespace std;

void readFromFile(int map[][10], int& rows, int& cols)
{
    ifstream input("input.txt");
    string str;
    rows = 0;
    cols = 0;
    while (getline(input, str))
    {
        if (rows == 0)
        {
            for (int i = 0; i < str.size(); i++)
                if (str[i] == 'X')
                    cols++;
            for (int i = 0; i < cols; i++)
                map[0][i] = -1;
        }
        else
        {
            int start = -1;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] == 'X' && start == -1)
                    start = i;
                if ((i - start) % 2 == 0)
                {
                    if (str[i] == 'X')
                        map[rows][(i - start) / 2] = -1;
                    else
                        map[rows][(i - start) / 2] = 0;
                }
                if ((i - start) / 2 >= cols)
                    break;
            }
        }
        rows++;
    }
}
