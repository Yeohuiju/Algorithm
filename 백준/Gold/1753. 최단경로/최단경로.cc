#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;
	int u, v, w;
	int now;
	priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> shortest;

	cin >> V >> E >> K;
	vector<vector<pair<int, int>>> graph(V + 1);
	vector<long> dist(V + 1, 5000000);
	vector<bool> processed(V + 1, false);

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	dist[K] = 0;
	shortest.push({ 0, K });

	while(!shortest.empty()) {
		now = shortest.top().second;
		shortest.pop();

		processed[now] = true;

		for (pair<int, int> i : graph[now]) {
			if (!processed[i.first]) {
				dist[i.first] = min(dist[i.first], dist[now] + i.second);

				shortest.push({ dist[i.first], i.first });			
			}
		}

		while (!shortest.empty() && processed[shortest.top().second])
			shortest.pop();
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == 5000000)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}