#include<bits/stdc++.h>
#include "preority_queue.h"
#include "fileIO.h"
using namespace std;

#define INF 1e9

void transformVertexToPoint(int vertex, int& x, int& y, int m)
{
    x = vertex % m;
    y = vertex / m;
}

int transformPointToVertex(int x, int y, int m)
{
    return y * m + x;
}

int h(int start, int finish, int m)
{
    int x1, y1, x2, y2;
    transformVertexToPoint(start, x1, y1, m);
    transformVertexToPoint(finish, x2, y2, m);
    return abs(x1 - x2) + abs(y1 - y2);
}

vector< int > aStar(int map[][100], int n, int m, int st, int fin)
{
    vector< bool > closed(n * m, false);
    PreorityQueue< pair< int, int > > open;
    vector< int > dist(n * m, INF), F(n * m, INF), parent(n * m, -1);
    open.push({0, st});
    dist[st] = 0;
    F[st] = h(st, fin, m);
    while(!open.empty())
    {
        int current = open.top().second;
        open.pop();
        if (closed[current])
            continue;
        if (current == fin)
            return parent;
        closed[current] = true;
        int x, y;
        transformVertexToPoint(current, x, y, m);
        vector< int > neighbours;
        if (x - 1 >= 0 && map[y][x - 1] != -1)
            neighbours.push_back(transformPointToVertex(x - 1, y, m));
        if (x + 1 < m && map[y][x + 1] != -1)
            neighbours.push_back(transformPointToVertex(x + 1, y, m));
        if (y - 1 >= 0 && map[y - 1][x] != -1)
            neighbours.push_back(transformPointToVertex(x, y - 1, m));
        if (y + 1 < n && map[y + 1][x] != -1)
            neighbours.push_back(transformPointToVertex(x, y + 1, m));
        for (int i = 0; i < neighbours.size(); i++)
        {
            int temp = dist[current] + 1;
            if (!closed[neighbours[i]] && dist[neighbours[i]] > temp)
            {
                parent[neighbours[i]] = current;
                dist[neighbours[i]] = temp;
                F[neighbours[i]] = temp + h(current, fin, m);
                open.push({F[neighbours[i]], neighbours[i]});
            }
        }
    }
    return parent;
}
