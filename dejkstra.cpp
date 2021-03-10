#include <bits/stdc++.h>
#include "preority_queue.h"
#include "fileIO.h"
#include "findWay.h"
//using namespace std;

#define INF 1000*1000

void convertSumFormToIndexes(int& x, int& y, int sumForm, int n){
    x = sumForm/n;
    y = sumForm%n;
}

int oneRelaxation(int map[][100], int x, int y, int v, int n, vector<int>& d, vector<int>& p, PreorityQueue < pair<int,int> >& q, int c){
        if( map[x][y] != -1 ){
            int to = x*n + y;
            if (d[v] + 1 < d[to]) {
                d[to] = d[v] + 1;
                p[to] = v;
                q.push (make_pair (d[to], to));
                //map[x][y]=c+'a';
                return 1;
            }

        }
    return 0;
}

vector<int> dejkstra(int map[][100], int n, int m, int st, int fin){
    vector<int> d(n*m, INF), p(n*m, -1);
    d[st] = 0;
    PreorityQueue < pair<int,int> > q;//making preority queue


    q.push (make_pair (0, st));
    int cnt=0;
    while(!q.empty()){
        int v = q.top().second;
        int cur_d = q.top().first;
        q.pop();
        if (cur_d > d[v])continue;//v is fictive

        int x, y;
        convertSumFormToIndexes(x, y, v, n);

        //relaxations
        int sum=0;
        sum+=oneRelaxation(map, x-1, y, v, n, d, p, q, cnt);
        sum+=oneRelaxation(map, x+1, y, v, n, d, p, q, cnt);
        sum+=oneRelaxation(map, x, y-1, v, n, d, p, q, cnt);
        sum+=oneRelaxation(map, x, y+1, v, n, d, p, q, cnt);
        findWayFromStartToFinish(p, map, n, m);
        writeToWindow(map, n, m);
        cout << endl << endl;
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
