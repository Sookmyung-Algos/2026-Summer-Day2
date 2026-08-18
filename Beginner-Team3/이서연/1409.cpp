#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

int N;
int M;
int closet[21];

int dp[21][21][21];

int solve(int idx, int open1, int open2) {

    if (idx == M)
        return 0;

    int& ret = dp[idx][open1][open2];

    if (ret != -1)
        return ret;

    int target = closet[idx];

    int move1 =
        abs(open1 - target)
        + solve(idx + 1, target, open2);

    int move2 =
        abs(open2 - target)
        + solve(idx + 1, open1, target);

    ret = min(move1, move2);

    return ret;
}

int main() {

    cin >> N;

    int open1, open2;
    cin >> open1 >> open2;

    cin >> M;

    for (int i = 0; i < M; i++)
        cin >> closet[i];

    memset(dp, -1, sizeof(dp));

    cout << solve(0, open1, open2);

    return 0;
}