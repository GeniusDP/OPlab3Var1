#include <bits/stdc++.h>

using namespace std;

void findWayFromStartToFinish(vector< int > parents, int map[][100], int n, int m)
{
    for (int fin = 0; fin < n * m; fin++)
    {
        if(parents[fin]==-1)continue;
        vector< int > way;
        int index = fin;
        way.push_back(index);
        while (parents[index] != -1)
        {
            index = parents[index];
            way.push_back(index);
        }
        reverse(way.begin(), way.end());
        for (int i = 0; i < way.size(); i++)
        {
            int y = way[i] / m;
            int x = way[i] % m;
            if (map[y][x] == -1)
                continue;
            if (i < 9)
            {
                map[y][x] = int('0' + i+1);
            }
            else
            {
                map[y][x] = int('a' + i - 9);
            }
        }
    }
}




//void findWayFromStartToFinish(vector< int > parents, int fin, int map[][100], int n, int m)
//{
//    vector< int > way;
//    int index = fin;
//    way.push_back(index);
//    while (parents[index] != -1)
//    {
//        index = parents[index];
//        way.push_back(index);
//    }
//    reverse(way.begin(), way.end());
//    for (int i = 0; i < way.size(); i++)
//    {
//        int y = way[i] / m;
//        int x = way[i] % m;
//        if (i < 9)
//        {
//            map[y][x] = int('0' + i + 1);
//        }
//        else
//        {
//            map[y][x] = int('a' + i - 9);
//        }
//    }
//}
