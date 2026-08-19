#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100001;
bool visited[MAX];
int dist[MAX];

int main() {
    int N, K;
    cin >> N >> K;

    queue<int> q;
    q.push(N);
    visited[N] = true;
    dist[N] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == K) break;

        int next[3] = { cur - 1, cur + 1, cur * 2 };
        for (int nx : next) {
            if (nx >= 0 && nx < MAX && !visited[nx]) {
                visited[nx] = true;
                dist[nx] = dist[cur] + 1;
                q.push(nx);
            }
        }
    }

    cout << dist[K] << endl;
}
