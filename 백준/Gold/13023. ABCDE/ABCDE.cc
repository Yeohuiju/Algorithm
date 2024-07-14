#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> graph;
static vector<bool> processed;
static int result;

void dfs(int s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int tmp1, tmp2;

	cin >> N >> M;
	graph = vector<vector<int>>(N + 1, vector<int>());
	processed = vector<bool>(N + 1, 0);

	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;

		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}

	for (int i = 0; i < N; i++) {
		if (!processed[i]) {
			result = 0;
			dfs(i);

			if (result >= 5)
				break;
		}
	}

	cout << (result >= 5);

	return 0;
}

void dfs(int s) {
	result++;
	processed[s] = 1;

	for (int i : graph[s]) {

		if (!processed[i])
			dfs(i);
	}

	if (result < 5) {
		processed[s] = 0;
		result--;
	}
}