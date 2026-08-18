#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int N, VS, VM;
        cin >> N >> VS >> VM;

        vector<int> v(N);

        for(int i = 0; i < N; i++) {
            cin >> v[i];
        }

        unsigned long long cur[16] = {};
        unsigned long long next[16];

        cur[VS / 64] |= (1ULL << (VS % 64));

        for(int i = 0; i < N; i++) {
            memset(next, 0, sizeof(next));

            for(int vol = 0; vol <= VM; vol++) {
                if(cur[vol / 64] & (1ULL << (vol % 64))) {

                    int up = vol + v[i];
                    int down = vol - v[i];

                    if(up <= VM) {
                        next[up / 64] |= (1ULL << (up % 64));
                    }

                    if(down >= 0) {
                        next[down / 64] |= (1ULL << (down % 64));
                    }
                }
            }

            for(int j = 0; j < 16; j++) {
                cur[j] = next[j];
            }
        }

        int ans = -1;

        for(int vol = VM; vol >= 0; vol--) {
            if(cur[vol / 64] & (1ULL << (vol % 64))) {
                ans = vol;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
