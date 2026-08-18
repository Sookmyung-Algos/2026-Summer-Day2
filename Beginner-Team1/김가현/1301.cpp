#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10001];
bool visited[1001];
int reach_count[1001];

void dfs(int node) {
    visited[node] = true;
    reach_count[node]++;

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int K, N, M;
    cin >> K >> N >> M;

    vector<int> start(K);
    for (int i = 0; i < K; i++) cin >> start[i];

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    // 각 병아리마다 DFS 실행
    for (int i = 0; i < K; i++) {
        
        for (int j = 1; j <= N; j++) {
            visited[j] = false;
        } 
        dfs(start[i]);
    }

    // 모든 병아리가 방문할 수 있는 마을 개수 세기
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (reach_count[i] == K) {
            ans++;
        }
    }

    cout << ans;
}