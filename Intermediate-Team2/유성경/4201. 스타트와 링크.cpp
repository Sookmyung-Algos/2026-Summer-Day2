// 정올 4201. 스타트와 링크
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> S(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> S[i][j];
        }
    }

    int minDiff = 2e9;

    for (int i = 0; i < (1 << N); i++)
    {
        int cnt = 0;

        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                cnt++;
            }
        }

        if (cnt == N / 2)
        {
            int scoreA = 0;
            int scoreB = 0;

            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    if ((i & (1 << j)) && (i & (1 << k)))
                    {
                        scoreA += S[j][k];
                    }
                    else if (!(i & (1 << j)) && !(i & (1 << k)))
                    {
                        scoreB += S[j][k];
                    }
                }
            }

            int diff = abs(scoreA - scoreB);
            if (diff < minDiff)
            {
                minDiff = diff;
            }
        }
    }

    cout << minDiff << "\n";

    return 0;
}
#endif