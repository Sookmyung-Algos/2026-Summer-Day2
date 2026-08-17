#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

vector<pair<int, int>> v;
int cost[15][15];
bool visited[15];
int n, mn = INF;

void dfs(int node, int cst, int cnt)
{
    if (cst >= mn)
        return;
    if (cnt == n)
    {
        if (cost[node][0] != 0)
            mn = min(mn, cst + cost[node][0]);
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (visited[i] == true || cost[node][i] == 0)
            continue;
        visited[i] = true;
        dfs(i, cst + cost[node][i], cnt + 1);
        visited[i] = false;
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    visited[0] = true;
    dfs(0, 0, 1);
    cout << mn;

    return 0;
}
