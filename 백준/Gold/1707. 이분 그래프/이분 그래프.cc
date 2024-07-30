#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> graph;
static vector<int> processed;
static bool result;

void checkBipartite(int s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, V, E;
	int n1, n2;

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> V >> E;
		graph = vector<vector<int>>(V + 1);
		processed = vector<int>(V + 1, -1);
		result = true;

		for (int j = 0; j < E; j++) {
			cin >> n1 >> n2;

			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
		}

		for (int k = 1; k <= V; k++) {
			if (result)
				checkBipartite(k);

			if (!result) {
				cout << "NO" << "\n";
				break;
			}
		}

		if (result)
			cout << "YES" << "\n";
	}
}

void checkBipartite(int s) {
	if (processed[s] == -1)
		processed[s] = 0;

	int idx = (processed[s] + 1) % 2;

	for (int i : graph[s]) {
		if (processed[i] == -1) {
			processed[i] = idx;
			checkBipartite(i);
		}
		else if (processed[i] == processed[s])
			result = false;
	}
}