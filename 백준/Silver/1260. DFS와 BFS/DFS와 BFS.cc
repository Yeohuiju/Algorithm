#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

static vector<vector<int>> graph;
static vector<bool> processed;
static vector<int> resultDFS;
static vector<int> resultBFS;

void dfs(int s);
void bfs(int s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	int tmp1, tmp2;

	cin >> N >> M >> V;
	graph = vector<vector<int>>(N + 1, vector<int>());
	processed = vector<bool>(N + 1, 0);

	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;

		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}

	for (int i = 0; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(V);

	processed = vector<bool>(N + 1, 0);

	bfs(V);

	for (int i : resultDFS)
		cout << i << ' ';

	cout << "\n";

	for (int i : resultBFS)
		cout << i << ' ';

	return 0;
}

void dfs(int s) {
	processed[s] = 1;
	resultDFS.push_back(s);

	for (int i : graph[s]) {
		if (!processed[i])
			dfs(i);
	}
}

void bfs(int s) {
	processed[s] = 1;
	resultBFS.push_back(s);

	queue<int> node;

	for (int i : graph[s]) {
		if (!processed[i]) {
			processed[i] = 1;
			resultBFS.push_back(i);
			node.push(i);
		}
	}

	while (!node.empty()) {
		int n = node.front();
		node.pop();

		for (int i : graph[n]) {
			if (!processed[i]) {
				processed[i] = 1;
				resultBFS.push_back(i);
				node.push(i);
			}
		}
	}
}