#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n); // 포털 이동 값 저장
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    int pos = 1; // 시작 위치
    while (pos < t) {
        pos += a[pos]; // 포털을 따라 이동
    }

    if (pos == t) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
