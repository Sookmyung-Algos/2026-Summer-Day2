#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cost[i][j];
        }
    }

    // 회사 하나만 존재하면 이동비용은 0
    if (N == 1) {
        cout << 0;
        return 0;
    }

    const int INF = INT_MAX / 2;
    int stateCount = 1 << N;

    vector<vector<int>> dp(stateCount, vector<int>(N, INF));

    // 0번 장소인 회사에서 출발
    dp[1][0] = 0;

    for (int visited = 0; visited < stateCount; visited++){
        for (int current = 0; current < N; current++){

            // 도달한 적 없는 상태
            if (dp[visited][current] == INF) continue;
            for (int next = 0; next < N; next++){

                // 이미 방문한 장소
                if (visited & (1 << next)) continue;
                // 이동할 수 없는 길
                if (cost[current][next] == 0) continue;

                int nextVisited = visited | (1 << next);
                dp[nextVisited][next] = min(dp[nextVisited][next], dp[visited][current] + cost[current][next]);
            }
        }
    }

    int allVisited = (1 << N) - 1;
    int answer = INF;

    for (int current = 1; current < N; current++){
        // 출발점으로 돌아갈 길이 있는지 확인
        if (cost[current][0] == 0) continue;
        answer = min(answer, dp[allVisited][current] + cost[current][0]);
    }

    cout << answer;

    return 0;
}
