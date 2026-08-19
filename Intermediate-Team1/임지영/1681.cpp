#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int cost[13][13];
long long dp[1 << 13][13]; // dp[방문집합][현재위치] = 최소 비용

const long long INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> cost[i][j];
        }
    }

    // dp 배열 초기화
    for(int i = 0; i < (1 << N); i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = INF;
        }
    }

    // 시작: 0번 장소만 방문한 상태, 현재 위치 0번
    dp[1][0] = 0;

    for(int visited = 1; visited < (1 << N); visited++){
        // 0번 장소는 항상 방문한 상태여야 함 (출발지)
        if(!(visited & 1)) continue;

        for(int cur = 0; cur < N; cur++){
            if(dp[visited][cur] == INF) continue;
            if(!(visited & (1 << cur))) continue;

            // 다음 방문할 장소 선택
            for(int nxt = 0; nxt < N; nxt++){
                if(visited & (1 << nxt)) continue; // 이미 방문함
                if(cost[cur][nxt] == 0) continue;  // 이동 불가

                int nextVisited = visited | (1 << nxt);
                long long nextCost = dp[visited][cur] + cost[cur][nxt];

                if(nextCost < dp[nextVisited][nxt]){
                    dp[nextVisited][nxt] = nextCost;
                }
            }
        }
    }

    // 모든 장소를 방문한 뒤 다시 0번(회사)으로 복귀
    long long answer = INF;
    int full = (1 << N) - 1;

    for(int cur = 1; cur < N; cur++){
        if(dp[full][cur] == INF) continue;
        if(cost[cur][0] == 0) continue; // 복귀 불가

        answer = min(answer, dp[full][cur] + cost[cur][0]);
    }

    cout << answer << "\n";

    return 0;
}