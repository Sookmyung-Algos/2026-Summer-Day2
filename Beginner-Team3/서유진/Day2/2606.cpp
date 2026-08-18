#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n,h;
    cin >> m >> n >> h;

    int arr[h][n][m];
    queue<tuple<int,int,int>> tomato;


    int dx[6] = {1,-1,0,0,0,0};
    int dy[6] = {0,0,1,-1,0,0};
    int dz[6] = {0,0,0,0,1,-1};

    int nx=0, ny=0, nz=0;


    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) {
                    tomato.push(tuple {k,j,i});
                }
            }
        }
    }

    while (!tomato.empty()) { 
        auto [x,y,z] = tomato.front();
        tomato.pop();

        for (int l=0; l<6; l++) {
            nx = x+dx[l];
            ny = y+dy[l];
            nz = z+dz[l];
            if (nx<0 || nx>=m || ny<0 || ny>=n || nz<0 || nz>=h) {
                continue;
            }
            else {
                if (arr[nz][ny][nx] == 0) {
                    arr[nz][ny][nx] = arr[z][y][x]+1;
                    tomato.push({nx,ny,nz});
                }
            }
        }               
    }

    int day=-1;

    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                if (arr[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                else if (arr[i][j][k] > day) {
                    day = arr[i][j][k];
                }
            }
        }
    }
    if (day == -1) {
        cout << -1;
        return 0;
    }

    cout << day-1;
}