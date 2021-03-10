#include <bits/stdc++.h>
#include "preority_queue.h"
using namespace std;

//function for conversion sum form of v to indexes in matrix
void convertSumFormToIndexes(int& x, int& y, int sumForm, int n);
//one relaxation
void oneRelaxation(int map[][100], int x, int y, int v, int n, vector<int>& d, vector<int>& p, priority_queue < pair<int,int> >& q, int c);
//dejkstra algorithm, which returns parent array
vector<int> dejkstra(int map[][100], int n, int m, int st, int fin);



