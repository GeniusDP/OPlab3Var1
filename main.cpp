#include <bits/stdc++.h>
//#include "fileIO.h"
//#include "dejkstra.h"
//#include "preority_queue.h"

using namespace std;

/*
    //очередь пар pair<int, int>

    PreorityQueue q;//сейчас пустой

        q.insert(<приоритет>, <доп информация>);

        q.empty();

        q.pop(); - удалить первый элемент

        q.extract(<приоритет>, <доп информация>); - удалить конкретную пару где-то в очереди

        q.head() - получать указатель на первый элемент

*/

int main()
{
    int rows, cols;
    int map[100][100]={};
    int stRow, stCol;
    int finRow, finCol;
    readFromFile(map, rows, cols, stRow, stCol, finRow, finCol);

    findShortestWay(map, rows, cols, stRow, stCol, finRow, finCol);

    writeToFile(map, rows, cols);
    return 0;
}
