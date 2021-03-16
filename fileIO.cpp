#include <bits/stdc++.h>
using namespace std;

void writeToWindow(int map[][100], int n, int m){//to output matrix with way.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            if(map[i][j]==-1)cout << "X ";
            else if(map[i][j]==0)cout << "  ";
            else cout << char(map[i][j]) << " ";
        cout << endl;
    }
}

void readFromFile(int map[][100], int& rows, int& cols)
{
    ifstream input("input.txt");
    string str;
    rows = 0;
    cols = 0;
    while (!input.eof())
    {
        getline(input, str);
        cout << str << endl;
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
