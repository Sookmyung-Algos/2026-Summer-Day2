#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    const int MAX = 100001;

    vector<int> dist(MAX, -1);
    queue<int> q;

    // 시작 위치
    dist[N] = 0;
    q.push(N);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // 재우가 있는 위치에 도착하면 끝
        if (now == K) {
            cout << dist[now] << '\n';
            return 0;
        }

        // 현재 위치에서 이동할 수 있는 세 가지 경우를 차례대로 bfs로 탐색.
        int next[3] = {
            now - 1,
            now + 1,
            now * 2
        };

        for (int i = 0; i < 3; i++) {
            int nextPos = next[i];

            // 범위 안에 있고, 아직 방문하지 않았다면 계속 bfs 진행
            if (nextPos >= 0 && nextPos < MAX && dist[nextPos] == -1) {
                dist[nextPos] = dist[now] + 1;
                q.push(nextPos);
            }
        }
    }

    return 0;
}