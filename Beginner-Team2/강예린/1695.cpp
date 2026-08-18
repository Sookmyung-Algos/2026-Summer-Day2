#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int map[25][25];
bool visited[25][25];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int DFS(int x, int y)
{
    visited[x][y] = true;

    int count = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;

        if (map[nx][ny] == 0 || visited[nx][ny])
            continue;

        count += DFS(nx, ny);
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;

        for (int j = 0; j < n; j++)
        {
            map[i][j] = line[j] - '0';
        }
    }

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                result.push_back(DFS(i, j));
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';

    for (int count : result)
    {
        cout << count << '\n';
    }

    return 0;
}