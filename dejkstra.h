#include <bits/stdc++.h>
using namespace std;

void convertSumFormToIndexes(int& x, int& y, int sumForm, int n);

void oneRelaxation(int map[][100], int x, int y, int v, int n, vector<int>& d, vector<int>& p, priority_queue < pair<int,int> >& q);

vector< pair<int, int> > dejkstra(int map[][100], int n, int m, int st, int fin);



