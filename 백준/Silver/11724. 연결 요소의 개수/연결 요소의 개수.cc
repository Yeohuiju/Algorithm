#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> graph;
static vector<bool> processed;

void dfs(int s);

int main() {

	int N, M;
	int tmp1, tmp2, start = 1;
	int finish = 0, result = 0;

	cin >> N >> M;
	graph = vector<vector<int>>(N + 1, vector<int>());
	processed = vector<bool>(N + 1, 0);

	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;

		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}

	while (!finish) {
		dfs(start);
		result++;

		for (int i = 1; i <= N; i++) {
			if (!processed[i]) {
				start = i;
				break;
			}

			if (i == N)
				finish = 1;
		}
	}

	cout << result;

	return 0;
}

void dfs(int s) {
	processed[s] = 1;

	for (int i = 0; i < graph[s].size(); i++) {
		int node = graph[s][i];

		if (!processed[node])
			dfs(node);
	}
}