#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> armies(m);

    for (int i = 0; i < m; i++) {
        cin >> armies[i];
    }

    int fedor;
    cin >> fedor;

    int answer = 0;

    for (int army : armies) {
        int differentBits = __builtin_popcount(army ^ fedor);

        if (differentBits <= k) {
            answer++;
        }
    }

    cout << answer;

    return 0;
}
