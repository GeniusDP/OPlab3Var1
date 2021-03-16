#include <bits/stdc++.h>

using namespace std;

void findWayFromStartToFinish(vector< int > parents, int map[][100], int n, int fin)
{
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
            int y = way[i] / n;
            int x = way[i] % n;
            if (map[y][x] == -1)
                continue;
            map[y][x] = 'a'+i;
        }
}
