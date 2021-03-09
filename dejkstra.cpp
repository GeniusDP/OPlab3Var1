#include <bits/stdc++.h>
#include "preority_queue.h"
using namespace std;

#define INF 1000*1000

void convertSumFormToIndexes(int& x, int& y, int sumForm, int n){
    x = sumForm/n;
    y = sumForm%n;
}

void oneRelaxation(int map[][100], int x, int y, int v, int n, vector<int>& d, vector<int>& p, PreorityQueue < pair<int,int> >& q){
        if( map[x][y] != -1 ){
            int to = x*n + y;
            if (d[v] + 1 < d[to]) {
                d[to] = d[v] + 1;
                p[to] = v;
                q.push (make_pair (d[to], to));
            }
        }
}

vector<int> dejkstra(int map[][100], int n, int m, int st, int fin){
    vector<int> d(n*m, INF), p(n*m, -1);
    d[st] = 0;
    PreorityQueue < pair<int,int> > q;


    q.push (make_pair (0, st));
    while(!q.empty()){
        int v = q.top().second;
        int cur_d = q.top().first;
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
    return p;
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
