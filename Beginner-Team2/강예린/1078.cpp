#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int col, row;
int board[101][101];
int dist[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void DFS(int x, int y, int time)
{
    if (dist[x][y] <= time)
        return;

    dist[x][y] = time;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > col || ny < 1 || ny > row)
            continue;

        if (board[nx][ny] == 0)
            continue;

        DFS(nx, ny, time + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> col >> row;

    for (int y = 1; y <= row; y++)
    {
        string line;
        cin >> line;

        for (int x = 1; x <= col; x++)
        {
            board[x][y] = line[x - 1] - '0';
            dist[x][y] = 1000000;
        }
    }

    int x, y;
    cin >> x >> y;

    DFS(x, y, 0);

    int answer = 0;
    int alive = 0;

    for (int y = 1; y <= row; y++)
    {
        for (int x = 1; x <= col; x++)
        {
            if (board[x][y] == 1)
            {
                if (dist[x][y] == 1000000)
                    alive++;
                else
                    answer = max(answer, dist[x][y] + 3);
            }
        }
    }

    cout << answer << '\n';
    cout << alive << '\n';

    return 0;
}