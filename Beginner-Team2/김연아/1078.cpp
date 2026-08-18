#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
    int n, m; // 열, 행
    cin >> n >> m;

    vector<vector<int>> map(m, vector<int>(n));
    vector<vector<int>> infected(m, vector<int>(n, -1)); // 오염된 시간 기록

    for (int i = 0; i < m; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    int sx, sy; // 시작 위치 (열, 행)
    cin >> sx >> sy;
    sx--; sy--; // 1-index → 0-index

    queue<pair<int, int>> q;
    infected[sy][sx] = 0; // 시작점 오염 시간 0
    q.push({ sy, sx });

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
            if (map[ny][nx] == 1 && infected[ny][nx] == -1) {
                infected[ny][nx] = infected[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }

    int maxTime = 0;
    int alive = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                if (infected[i][j] == -1) {
                    alive++; // 끝까지 오염되지 않음
                }
                else {
                    maxTime = max(maxTime, infected[i][j] + 3);
                }
            }
        }
    }

    cout << maxTime << "\n" << alive << "\n";
    return 0;
}
