#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int dfs(int x, int y) {
    visited[x][y] = true;
    int count = 1; // 현재 집 포함

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
            if (!visited[nx][ny] && grid[nx][ny] == 1) {
                count += dfs(nx, ny);
            }
        }
    }
    return count;
}

int main() {
    cin >> N;
    grid.assign(N, vector<int>(N));
    visited.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            grid[i][j] = line[j] - '0';
        }
    }

    vector<int> complexes;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                int size = dfs(i, j);
                complexes.push_back(size);
            }
        }
    }

    sort(complexes.begin(), complexes.end());

    cout << complexes.size() << "\n";
    for (int c : complexes) cout << c << "\n";

    return 0;
}
