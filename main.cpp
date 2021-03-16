#include <bits/stdc++.h>
#include "fileIO.h"
#include "a_star.h"
#include "findWay.h"
using namespace std;

int main()
{
    int rows, cols;
    int map[100][100]={};
    //4 3 1 6
    int stRow=1, stCol=8;
    int finRow=1, finCol=1;



    readFromFile(map, rows, cols);
    vector<int> parent = aStar(map, rows, cols, stRow*rows+stCol, finRow*rows+finCol);

    findWayFromStartToFinish(parent, map, rows, finRow*rows+finCol);


    if(parent[finRow*rows+finCol]==-1)cout << "NO SOLUTION!";
    else{
        writeToWindow(map, rows, cols);
    }
    return 0;
}
