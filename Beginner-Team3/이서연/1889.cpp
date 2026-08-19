#include <iostream>
using namespace std;

int N;
int answer = 0;

bool col[13];
bool diagonal1[25];
bool diagonal2[25]; 

void dfs(int row) {
    if (row == N) {
        answer++;
        return;
    }

    for (int c = 0; c < N; c++) {

        if (col[c] ||
            diagonal1[row + c] ||
            diagonal2[row - c + N - 1])
            continue;

        col[c] = true;
        diagonal1[row + c] = true;
        diagonal2[row - c + N - 1] = true;

        dfs(row + 1);

        col[c] = false;
        diagonal1[row + c] = false;
        diagonal2[row - c + N - 1] = false;
    }
}

int main() {
    cin >> N;

    dfs(0);

    cout << answer;

    return 0;
}