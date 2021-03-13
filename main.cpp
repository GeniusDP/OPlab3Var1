#include <bits/stdc++.h>
#include "fileIO.h"
#include "dejkstra.h"
#include "findWay.h"
using namespace std;

int main()
{
    int rows, cols;
    int map[100][100]={};
    int stRow=5, stCol=1;
    int finRow=1, finCol=6;

    readFromFile(map, rows, cols);
    vector<int> parent = dejkstra(map, rows, cols, stRow*rows+stCol, finRow*rows+finCol);
    if(parent[finRow*rows+finCol]==-1)cout << "NO SOLUTION!";
    else{
        findWayFromStartToFinish(parent, finRow*rows+finCol, map, rows, cols);
        writeToWindow(map, rows, cols);
    }
    return 0;
}
