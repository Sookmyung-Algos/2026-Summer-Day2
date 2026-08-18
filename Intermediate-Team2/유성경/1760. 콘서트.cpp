// 정올 1760. 콘서트
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N, VS, VM;
        cin >> N >> VS >> VM;

        vector<int> V(N + 1);
        for (int i = 1; i <= N; i++)
        {
            cin >> V[i];
        }

        bitset<1001> mask;
        for (int i = 0; i <= VM; i++)
        {
            mask.set(i);
        }

        bitset<1001> dp;

        dp.set(VS);

        for (int i = 1; i <= N; i++)
        {
            dp = ((dp << V[i]) | (dp >> V[i])) & mask;
        }

        int maxV = -1;
        for (int i = VM; i >= 0; i--)
        {
            if (dp.test(i))
            {
                maxV = i;
                break;
            }
        }

        cout << maxV << "\n";
    }

    return 0;
}
#endif