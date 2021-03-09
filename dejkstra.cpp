#include <bits/stdc++.h>

using namespace std;

#define INF 1000*1000


vector< pair<int, int> > dejkstra(int map[][100], int n, int m){
    int st = 5*n+1;
    int fin = 1*n+6;

    vector<int> d(n*m, INF), p(n*m, -1);
    d[st] = 0;
    priority_queue < pair<int,int> > q;


    q.push (make_pair (0, st));
    while(!q.empty()){
        int v = q.top().second;
        int cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v])continue;

        int x, y;
        convertSumFormToIndexes(x, y, v, n);

        int len=1;
        oneRelaxation(map, x-1, y, v, n, d, p, q);
        oneRelaxation(map, x+1, y, v, n, d, p, q);
        oneRelaxation(map, x, y-1, v, n, d, p, q);
        oneRelaxation(map, x, y+1, v, n, d, p, q);
    }
    vector< pair<int, int> > way(1, make_pair(fin/n, fin%n));
    int i=fin;
    while(p[i] != -1){
        way.push_back(make_pair(p[i]/n, p[i]%n));
        i=p[i];
    }
    reverse(way.begin(), way.end());
    return way;
}

/*
X X X X X X X X
X       X X   X
X   X   X X   X
X   X         X
X   X   X   X X
X   X   X   X X
X   X       X X
X X X X X X X X */
