#include <iostream>
#include <queue>

using namespace std;

bool visited[100001];
int dist[100001];

void bfs(int start){
    queue<int> q;

    q.push(start);
    visited[start]=true;
    dist[start]=0;

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        int next[3] = {
            curr - 1,
            curr + 1,
            curr * 2
        };

        for (int i = 0; i < 3; i++) {
            int n = next[i];

            if (n < 0 || n > 100000)
                continue;

            if (!visited[n]) {
                visited[n] = true;
                dist[n] = dist[curr] + 1;
                q.push(n);
            }
        }
    }
}

int main() {
    int N, K;
    cin >>N >>K;

    bfs(N);
    cout << dist[K];

    return 0;
}