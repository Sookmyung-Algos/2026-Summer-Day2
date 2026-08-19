#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    int a[30001];

    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    int cur = 1;

    while (cur < t) {
        cur += a[cur];
    }

    if (cur == t)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}