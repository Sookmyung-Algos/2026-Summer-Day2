#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int S[20][20];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    int answer = INT_MAX;
    int limit = 1 << N;

    for (int mask = 0; mask < limit; mask++) {
        if (!(mask & 1)) continue;
        if (__builtin_popcount(mask) != N / 2) continue;

        int scoreA = 0;
        int scoreB = 0;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if ((mask & (1 << i)) && (mask & (1 << j))) {
                    scoreA += S[i][j] + S[j][i];
                }
                else if (!(mask & (1 << i)) && !(mask & (1 << j))) {
                    scoreB += S[i][j] + S[j][i];
                }
            }
        }

        answer = min(answer, abs(scoreA - scoreB));
    }

    cout << answer << '\n';

    return 0;
}