#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n_queens(int n, int r, vector<vector<int>>& vec) {
    int n_check=0;

    if (r == n) {
        return 1;
    }

    for (int c=0; c<n; c++) {
        
        if (vec[r][c] == 0) {
            vec[r][c] = 1;

            vector<pair<int,int>> changed;

            for (int i=r+1; i<n; i++) {
                if (vec[i][c] == 0) {
                    vec[i][c] = -1;
                    changed.push_back(make_pair(i,c));
                }              
                if (c+i-r < n) {
                    if (vec[i][c+i-r] == 0) {
                        vec[i][c+i-r] = -1;
                        changed.push_back(make_pair(i,c+i-r));
                    }
                }
                if (c-i+r >= 0) {
                    if (vec[i][c-i+r] == 0) {
                        vec[i][c-i+r] = -1;
                        changed.push_back(make_pair(i,c-i+r));
                    }
                }
            }

            n_check += n_queens(n,r+1,vec); 

            while (!changed.empty()) {
                auto [x,y] = changed.back();
                changed.pop_back();
                vec[x][y] = 0;
            }
            vec[r][c] = 0;
        }
    }
    return n_check;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> vec (n,vector<int>(n,0));

    int num = n_queens(n,0,vec);
    cout << num;
    
}