#include <iostream>
#include <algorithm>
using namespace std;

int n;
int col[15]; 
int cnt = 0; // 가능한 배치 수

bool promising(int row){ // 충돌 검사
    for (int i =0; i < row; i++){
        if (col[i] == col[row]) // 같은 열인지
            return false;
        if (abs(col[i] - col[row]) == abs(i-row)) // 대각선상(행의 차이 == 열의 차이)에 있는지
            return false;
    }
    return true;
}

void dfs(int row){
    if (row == n){
        cnt++;
        return;
    }

    for(int i = 0; i < n; i++) { // 현재 행에 0 ~ n-1 열까지 하나씩 퀸 놓아보기
        col[row] = i;
        if (promising(row)) // 백트래킹 : 충돌하면 포기
            dfs(row + 1);
    }
    
}

int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);

cin >> n;
dfs(0);
cout << cnt << "\n";

return 0;


}