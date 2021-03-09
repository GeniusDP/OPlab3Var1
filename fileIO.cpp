#include <iostream>
using namespace std;

void writeToWindow(int map[][100], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            if(map[i][j]==-1)cout << "X ";
            else if(map[i][j]==0)cout << "  ";
            else cout << char(map[i][j]) << " ";
        cout << endl << endl;
    }
}
