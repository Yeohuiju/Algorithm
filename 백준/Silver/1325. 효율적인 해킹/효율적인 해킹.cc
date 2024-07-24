#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> computer;
static vector<int> processed;

int dfs(int s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int s, e;
	int maximum = 0;

	cin >> N >> M;
	computer.resize(N + 1);
	vector<int> result(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> e >> s;

		computer[s].push_back(e);
	}

	for (int i = 1; i <= N; i++) {
		processed.clear();
		processed.resize(N + 1, 0);
		result[i] = dfs(i);
		if (result[i] > maximum)
			maximum = result[i];
	}

	for (int i = 1; i <= N; i++) {
		if (result[i] == maximum)
			cout << i << ' ';
	}

	return 0;
}

int dfs(int s) {
	int result = 0;
	processed[s] = 1;

	for (int i : computer[s]) {
		if (!processed[i]) {
			processed[i] = 1;
			result++;
			result += dfs(i);
		}
	}

	return result;
}