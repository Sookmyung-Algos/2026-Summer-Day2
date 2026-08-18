#include <iostream>
#include <vector>

using namespace std;

bool visited[1001];
int cnt[1001];

vector<int> graph[1001]; 

void dfs(int node){
    visited[node] = true;
    cnt[node]++;

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];

        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main(){
    int K, N, M;
    cin >> K>> N>> M;

    vector<int> chick(K);

    for (int i=0; i<K;i++){
        cin >> chick[i];
    }

    for (int i=0; i<M; i++){
        int a, b;
        cin >>a >>b;

        graph[a].push_back(b);
    }

    for (int i = 0; i < K; i++){
        for (int j=1; j<=N; j++){
            visited[j] = false;
        }

        dfs(chick[i]);
    }

    int answer=0;

    for (int i = 1; i <= N; i++){
        if (cnt[i] == K){
            answer++;
        }
    }

    cout <<answer;
    return 0;
}