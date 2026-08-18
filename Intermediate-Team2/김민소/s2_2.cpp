#include <iostream>
#include <vector>
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

        vector<bool> dp(VM + 1, false);

        dp[VS] = true;

        for (int i = 0; i < N; i++) {
            vector<bool> next(VM + 1, false);

            for (int volume = 0; volume <= VM; volume++) {
                if (!dp[volume])
                    continue;

                if (volume + V[i] <= VM) {
                    next[volume + V[i]] = true;
                }

                if (volume - V[i] >= 0) {
                    next[volume - V[i]] = true;
                }
            }

            dp = next;
        }

        int answer = -1;
        for (int volume = VM; volume >= 0; volume--) {
            if (dp[volume]) {
                answer = volume;
                break;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}