#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int S[20][20];
bool selected[20];

int answer = 1e9;

void dfs(int idx, int cnt) {
    if (cnt == N / 2) {
        int scoreA = 0;
        int scoreB = 0;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {

                if (selected[i] && selected[j]) {
                    scoreA += S[i][j] + S[j][i];
                }

                else if (!selected[i] && !selected[j]) {
                    scoreB += S[i][j] + S[j][i];
                }
            }
        }

        answer = min(answer, abs(scoreA - scoreB));
        return;
    }

    if (idx == N) {
        return;
    }

    selected[idx] = true;
    dfs(idx + 1, cnt + 1);

    selected[idx] = false;
    dfs(idx + 1, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    selected[0] = true;
    dfs(1, 1);

    cout << answer << '\n';

    return 0;
}