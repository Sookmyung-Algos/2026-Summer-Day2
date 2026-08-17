#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(m);
    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }
    int fedor;
    cin >> fedor;

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (__builtin_popcount(x[i] ^ fedor) <= k)
            ans++;
    }
    cout << ans;

    return 0;
}
