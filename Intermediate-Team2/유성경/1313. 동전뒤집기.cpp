// 정올 1313. 동전뒤집기
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

#ifdef _MSC_VER
#include <intrin.h>
#define POPCOUNT(x) __popcnt64(x)
#else
#define POPCOUNT(x) __builtin_popcountll(x)
#endif

using namespace std;

int get_cost(long long row_state, int N, const vector<long long>& cols)
{
    int cost = 0;
    for (int j = 0; j < N; j++)
    {
        long long state = cols[j] ^ row_state;
        int tailCnt = POPCOUNT(state);
        int headCnt = N - tailCnt;

        if (tailCnt < headCnt)
        {
            cost += tailCnt;
        }
        else
        {
            cost += headCnt;
        }
    }
    return cost;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<long long> cols(N, 0);

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++)
        {
            if (s[j] == 'T')
            {
                cols[j] |= (1LL << i);
            }
        }
    }

    srand((unsigned int)time(NULL));

    long long current_state = 0;
    for (int i = 0; i < N; i++)
    {
        if (rand() % 2 == 1)
        {
            current_state |= (1LL << i);
        }
    }

    int current_cost = get_cost(current_state, N, cols);
    int min_cost = current_cost;

    double T = 1000.0;           
    double cooling_rate = 0.999; 

    clock_t start_time = clock();
    int iter = 0;

    while (true)
    {
        iter++;

        if (iter % 1000 == 0)
        {
            if ((double)(clock() - start_time) / CLOCKS_PER_SEC > 0.85)
            {
                break;
            }
        }

        int bit = rand() % N;
        long long next_state = current_state ^ (1LL << bit);
        int next_cost = get_cost(next_state, N, cols);

        if (next_cost <= current_cost)
        {
            current_state = next_state;
            current_cost = next_cost;

            if (current_cost < min_cost)
            {
                min_cost = current_cost;
            }
        }
        else
        {
            double p = exp((current_cost - next_cost) / T);
            double r = (double)rand() / RAND_MAX;

            if (r < p)
            {
                current_state = next_state;
                current_cost = next_cost;
            }
        }

        T *= cooling_rate;

        if (T < 0.001)
        {
            T = 1000.0;
            current_state = 0;
            for (int i = 0; i < N; i++)
            {
                if (rand() % 2 == 1)
                {
                    current_state |= (1LL << i);
                }
            }
            current_cost = get_cost(current_state, N, cols);
        }
    }

    cout << min_cost << "\n";

    return 0;
}
#endif