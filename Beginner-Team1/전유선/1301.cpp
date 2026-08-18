#include <iostream>
#include <vector>

using namespace std;

// 현재 마을이 now, 아래 2차원 벡터 받아오는 graph, 
// 현재 병아리의 방문 마을 visited, 마을에 방문 가능한 병아리 마리수
void dfs(int now,
	vector<vector<int>>& graph,
	vector<bool>& visited,
	vector<int>& count) {

	visited[now] = true;
	count[now]++;

	// 길이 있고 아직 방문을 안 했으면 재귀
	for (int i = 1; i < graph.size(); i++) {
		if (graph[now][i] == 1 && !visited[i]) {
			dfs(i, graph, visited, count);
		}
	}
}

int main() {
	int k, n, m;
	int mstart, mend;
	cin >> k >> n >> m;

	// 학생이 사는 마을
	vector<int> karr(k);

	// 이차원 배열로 하려다가 뭔가 이상해서 벡터로... 배열 0으로 초기화.
	vector<vector<int>> marr(n + 1, vector<int>(n + 1, 0));

	// k랑 m값 입력받기
	for (int i = 0; i < k; i++) {
		cin >> karr[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> mstart >> mend;
		marr[mstart][mend] = 1;
	}

	// 각 마을에 몇 마리의 병아리가 도달할 수 있는지
	vector<int> count(n + 1, 0);

	// 병아리마다 dfs
	for (int i = 0; i < k; i++) {
		// 병아리마다 방문 가능 마을 나타내는 visited, false로 초기화.
		vector<bool> visited(n + 1, false);

		dfs(karr[i], marr, visited, count);
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (count[i] == k) {
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}