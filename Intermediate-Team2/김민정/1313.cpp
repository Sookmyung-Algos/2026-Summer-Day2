#include <bits/stdc++.h>
using namespace std;

int n;
unsigned int a[33];

int calc(unsigned int mask) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        int t = __builtin_popcount(a[i] ^ mask);
        sum += min(t, n - t);
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < n; j++) {
            if(s[j] == 'T')
                a[i] |= (1u << j);
        }
    }

    mt19937 gen(1919);
    uniform_real_distribution<double> rnd(0.0, 1.0);

    int ans = n * n;

    for(int r = 0; r < 20; r++) {
        unsigned int cur;

        if(r == 0)
            cur = 0;
        else
            cur = gen();

        if(n < 32)
            cur &= ((1u << n) - 1);

        int now = calc(cur);
        double temp = 1.0;

        for(int k = 0; k < 15000; k++) {
            int p = gen() % n;

            unsigned int next = cur ^ (1u << p);
            int nv = calc(next);

            if(nv <= now ||
               exp((now - nv) / (10.0 * temp)) > rnd(gen)) {
                cur = next;
                now = nv;
            }

            ans = min(ans, now);
            temp *= 0.9996;
        }
    }

    cout << ans;

    return 0;
}
