// Day2 - 정올 1760번 : 콘서트
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, VS, VM;
        cin >> N >> VS >> VM;

        vector<int> V(N);

        for (int i = 0; i < N; i++) {
            cin >> V[i];
        }

        vector<vector<bool>> dp(N + 1, vector<bool>(VM + 1, false));

        // 시작 볼륨
        dp[0][VS] = true;

        for (int i = 0; i < N; i++) {
            for (int volume = 0; volume <= VM; volume++) {
                if (!dp[i][volume]) {
                    continue;
                }

                int increased = volume + V[i];
                int decreased = volume - V[i];

                if (increased <= VM) {
                    dp[i + 1][increased] = true;
                }

                if (decreased >= 0) {
                    dp[i + 1][decreased] = true;
                }
            }
        }

        // 마지막 곡 연주 직전의 최대 볼륨 탐색
        int answer = -1;

        for (int volume = VM; volume >= 0; volume--) {
            if (dp[N][volume]) {
                answer = volume;
                break;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
