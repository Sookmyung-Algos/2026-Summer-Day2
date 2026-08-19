#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int s[20][20];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    int ans = 1000000000;

    for(int mask = 0; mask < (1 << n); mask++) {
        if(__builtin_popcount(mask) != n / 2)
            continue;

        if((mask & 1) == 0)
            continue;

        int start = 0;
        int link = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if((mask & (1 << i)) && (mask & (1 << j))) {
                    start += s[i][j];
                }

                if(!(mask & (1 << i)) && !(mask & (1 << j))) {
                    link += s[i][j];
                }
            }
        }

        int diff = abs(start - link);

        if(diff < ans)
            ans = diff;
    }

    cout << ans;

    return 0;
}
