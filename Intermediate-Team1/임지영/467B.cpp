#include <iostream>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int x[1001];
    for(int i = 0; i <= m; i++){
        cin >> x[i];
    }

    int fedor = x[m]; // 마지막(m+1번째) 플레이어가 fedor
    int cnt = 0;

    for(int i = 0; i < m; i++){
        int diff = x[i] ^ fedor;       // XOR로 다른 비트만 1로 남김
        int bits = __builtin_popcount(diff); // 1의 개수 = 서로 다른 병종 수

        if(bits <= k) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}