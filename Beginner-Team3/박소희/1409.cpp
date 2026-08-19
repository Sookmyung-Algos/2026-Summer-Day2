#include <iostream>
#include <algorithm>
using namespace std;

int n, d1, d2, k;
int seq[21];

int dfs(int idx, int left, int right){ // 현재 상황(차례, 문이 없는 위치)
    if (idx == k) // 모든 요청 처리 완료
        return 0;

    int target = seq[idx];

    // 이동횟수
    int moveLeft = abs(left - target) + dfs(idx + 1, target, right);
    int moveRight = abs(right - target) + dfs(idx + 1, left, target);

    return min(moveLeft, moveRight);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d1 >> d2 >> k;

    for (int i = 0; i < k; i++){
        cin >> seq[i];
    }

    cout << dfs(0, d1, d2);

    return 0;

}