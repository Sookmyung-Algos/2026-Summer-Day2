#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int box[100][100][100];
// 오프셋 배열
int dh[6] = {0, 0, 0, 0, 1, -1};  // 위아래 이동
int dn[6] = {0, 0, 1, -1, 0, 0};  // 앞뒤 이동
int dm[6] = {1, -1, 0, 0, 0, 0};  // 좌우 이동

int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);

int M, N, H;
cin >> M >> N >> H;
queue<tuple<int, int, int>> q;

for(int h=0; h<H; h++){
    for(int n=0; n<N; n++){
        for (int m=0; m<M; m++){
            cin >> box[h][n][m];

            if (box[h][n][m] == 1)
                q.push({h, n, m});
        }
    }
}


int day = 0;

while(!q.empty()) { // 큐에 토마토가 있는 동안
    auto [h, n, m] = q.front(); // 큐에 있는 토마토 위치
    q.pop();

    for (int d = 0; d < 6; d++){
        int nh = h + dh[d]; // 인접 좌표들 구하기
        int nn = n + dn[d];
        int nm = m + dm[d]; 

        // 계산한 좌표가 상자 밖인 경우
        if (nh < 0 || nh >= H || nn < 0 || nn >= N || nm < 0 || nm >= M) 
        continue;
        // 이미 익었거나 토마토가 없는 경우(1, -1)
        if (box[nh][nn][nm] != 0) continue;

        // 안 익은 토마토의 경우 익히기
        box[nh][nn][nm] = box[h][n][m] + 1; 
        day = max(day, box[nh][nn][nm] - 1);
        q.push({nh, nn, nm});
    }
}
    // 안 익은 토마토 있는지 확인
    for (int h = 0; h < H; h++)
        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++)
                if (box[h][n][m] == 0) 
                    cout << -1;
                    return 0;

    cout << day;


return 0;

}