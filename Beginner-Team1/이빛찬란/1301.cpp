#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1001];
bool vis[1001][1001];   // vis[s][v] = s에서 v로 도달 가능한지
bool done[1001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start][start] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (!vis[start][next]) {
                vis[start][next] = true;
                q.push(next);
            }
        }
    }
    done[start] = true;
}

int main() {
    int K, N, M;
    cin >> K >> N >> M;

    vector<int> start(K);
    for (int i = 0; i < K; i++) cin >> start[i];

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 0; i < K; i++)
        if (!done[start[i]]) bfs(start[i]);

    int count = 0;
    for (int v = 1; v <= N; v++) {
        bool common = true;
        for (int i = 0; i < K; i++) {
            if (!vis[start[i]][v]) { common = false; break; }
        }
        if (common) count++;
    }

    cout << count << endl;
}
