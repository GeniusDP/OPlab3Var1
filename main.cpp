#include <bits/stdc++.h>
//#include "fileIO.h"
//#include "dejkstra.h"
//#include "preority_queue.h"

using namespace std;

/*
    //������� ��� pair<int, int>

    PreorityQueue q;//������ ������

        q.insert(<���������>, <��� ����������>);

        q.empty();

        q.pop(); - ������� ������ �������

        q.extract(<���������>, <��� ����������>); - ������� ���������� ���� ���-�� � �������

        q.head() - �������� ��������� �� ������ �������

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
