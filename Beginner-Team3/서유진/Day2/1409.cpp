#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int path (int m, int n, int c, vector<int>& arr) {
    int num=0;

    if (c < arr.size()) {
        int a = arr[c];

        num += min(abs(a-m) + path(a,n,c+1,arr), abs(a-n) + path(m,a,c+1,arr));
        return num;
    }
    return num;
}

int main() {
    int p,m,n,length;
    cin >> p;
    cin >> m >> n;
    cin >> length;
    
    vector<int> arr(length);

    for (int i=0; i<length; i++) {
        cin >> arr[i];
    }

    int num = path(m,n,0,arr);

    cout << num;
    
}