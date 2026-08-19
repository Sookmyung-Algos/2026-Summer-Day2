// Day2 - 정올 4201번 : 스타트와 링크
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int S[20][20];
int answer = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    int totalMasks = 1 << N;

    for (int mask = 0; mask < totalMasks; mask++) {
        // 첫 번째 요리에 항상 0번 재료를 포함시켜 중복 제거
        if ((mask & 1) == 0) {
            continue;
        }

        // 첫 번째 요리에 포함된 재료 수가 N/2인지 확인
        if (__builtin_popcount(mask) != N / 2) {
            continue;
        }

        int firstScore = 0;
        int secondScore = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mask & (1 << i)) {
                    if (mask & (1 << j)) {
                        firstScore += S[i][j];
                    }
                } else {
                    if ((mask & (1 << j)) == 0) {
                        secondScore += S[i][j];
                    }
                }
            }
        }

        answer = min(answer, abs(firstScore - secondScore));
    }

    cout << answer << '\n';

    return 0;
}
