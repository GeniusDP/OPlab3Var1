#include <bits/stdc++.h>
#include "preority_queue.h"
#include "fileIO.h"

#define INF 1000*1000

void convertSumFormToIndexes(int& x, int& y, int sumForm, int n){
    x = sumForm/n;
    y = sumForm%n;
}

void findHeuristic(int map[][100], int h[][100], int n, int m){
    for(int i1=0; i1<n; i1++){
        for(int j1=0; j1<m; j1++){
            for(int i2=0; i2<n; i2++){
                for(int j2=0; j2<m; j2++){
                    h[i1*n+j1][i2*n+j2] = h[i2*n+j2][i1*n+j1] = abs(i1-i2) + abs(j1-j2);
                }
            }
        }
    }
}


void relax(int map[][100], int curr, int neighbour_i, int neighbour_j, vector<int>& f,  vector<int>& g, vector<bool>& closed, vector<int>& from, PreorityQueue< pair<int,int> >& open, vector<bool>& isOpenNow, int n, int fin, int h[][100]){
    if(!closed[neighbour_i*n + neighbour_j] && map[neighbour_i][neighbour_j]!=-1){
        int temp_g = g[curr]+1;
        if(!isOpenNow[neighbour_i*n + neighbour_j] || temp_g<g[neighbour_i*n + neighbour_j]){
            from[neighbour_i*n + neighbour_j] = curr;
            g[neighbour_i*n + neighbour_j] = temp_g;
            f[neighbour_i*n + neighbour_j] = g[neighbour_i*n + neighbour_j] + h[neighbour_i*n + neighbour_j][fin];
        }

        if(!isOpenNow[neighbour_i*n + neighbour_j]){
            open.push(make_pair(f[neighbour_i*n + neighbour_j], neighbour_i*n + neighbour_j));
        }
    }
}

vector<int> aStar(int map[][100], int n, int m, int st, int fin){
    int h[100][100]={};
    findHeuristic(map, h, n, m);
    vector<bool> closed(n*m, false);
    PreorityQueue< pair<int,int> > open;
    vector<bool> isOpenNow(n*m, false);
    vector<int> from(n*m, -1);
    vector<int> g(n*m, INF);
    vector<int> f(n*m, INF);
    g[st] = 0;
    f[st] = g[st] + h[st][fin];
    isOpenNow[st] = true;
    open.push(make_pair(f[st], st));
    while(!open.empty()){
        int curr = open.top().second;
        int neighbour_i, neighbour_j;
        convertSumFormToIndexes(neighbour_i, neighbour_j, open.top().second, n);

        //extracting current node from the heap
        open.pop();
        closed[curr]=true;

        //left
        relax(map, curr, neighbour_i, neighbour_j-1, f, g, closed, from, open, isOpenNow, n, fin, h);
        relax(map, curr, neighbour_i, neighbour_j+1, f, g, closed, from, open, isOpenNow, n, fin, h);
        relax(map, curr, neighbour_i-1, neighbour_j, f, g, closed, from, open, isOpenNow, n, fin, h);
        relax(map, curr, neighbour_i+1, neighbour_j, f, g, closed, from, open, isOpenNow, n, fin, h);

    }
    return from;
}
