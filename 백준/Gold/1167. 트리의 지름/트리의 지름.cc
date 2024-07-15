#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

static vector<vector<pair<int, int>>> tree;
static vector<bool> processed;
static vector<int> dist;

void bfs(int s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V;
	int node1, node2, d;
	int maxIdx = 1;

	cin >> V;
	tree.resize(V + 1);
	processed.resize(V + 1);
	dist.resize(V + 1);

	for (int i = 1; i <= V; i++) {
		cin >> node1 >> node2;

		while (node2 != -1) {
			cin >> d;
			tree[node1].push_back({ node2, d });
			cin >> node2;
		}
	}

	fill(processed.begin(), processed.end(), false);
	fill(dist.begin(), dist.end(), 0);
	bfs(1);

	for (int i = 2; i <= V; i++) {
		if (dist[maxIdx] < dist[i])
			maxIdx = i;
	}

	fill(processed.begin(), processed.end(), false);
	fill(dist.begin(), dist.end(), 0);
	bfs(maxIdx);

	sort(dist.begin(), dist.end());

	cout << dist[V];

	return 0;
}

void bfs(int s) {
	queue<int> node;

	processed[s] = 1;
	node.push(s);

	while (!node.empty()) {
		int tmp = node.front();
		node.pop();

		for (pair<int, int> v : tree[tmp]) {
			if (!processed[v.first]) {
				dist[v.first] = v.second + dist[tmp];
				processed[v.first] = 1;
				node.push(v.first);
			}
		}
	}
}