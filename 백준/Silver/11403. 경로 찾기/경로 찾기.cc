#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> graph;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;
	graph.resize(n);
	fill(graph.begin(), graph.end(), vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	}

	for (int k = 0; k < n; k++) {
		for (int s = 0; s < n; s++) {
			for (int e = 0; e < n; e++) {
				if (graph[s][k] && graph[k][e])
					graph[s][e] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << graph[i][j] << ' ';

		cout << "\n";
	}

	return 0;
}