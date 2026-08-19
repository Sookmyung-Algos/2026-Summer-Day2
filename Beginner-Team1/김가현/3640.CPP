#include <iostream>
#include <queue>

using namespace std;

int dist[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    if (N == K) {
        cout << 0;
        return 0;
    }

    queue<int> q;
    q.push(N);
    dist[N] = 1;

    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int next_p[3] = {curr - 1, curr + 1, curr * 2};

        for (int next : next_p) {
            if (next >= 0 && next <= 100000) {
                if (dist[next] == 0) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);

                    if (next == K) {
                        cout << dist[next] - 1;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}