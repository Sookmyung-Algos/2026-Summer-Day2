#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, VS, VM;
        cin >> N >> VS >> VM;

        vector<int> V(N);

        for (int i = 0; i < N; i++) {
            cin >> V[i];
        }

        bitset<1001> cur;
        cur[VS] = 1;

        for (int i = 0; i < N; i++) {
            bitset<1001> next;

            next |= (cur << V[i]);
            next |= (cur >> V[i]);

            for (int volume = VM + 1; volume <= 1000; volume++) {
                next[volume] = 0;
            }

            cur = next;
        }

        int answer = -1;

        for (int volume = VM; volume >= 0; volume--) {
            if (cur[volume]) {
                answer = volume;
                break;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}