#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, S, E;
	int s, e, w;
	int now;
	priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> shortest;

	cin >> N >> M;
	vector<vector<pair<int, int>>> city(N + 1);
	vector<long> dist(N + 1, LONG_MAX);
	vector<bool> processed(N + 1, false);

	for (int i = 0; i < M; i++) {
		cin >> s >> e >> w;
		city[s].push_back({ e, w });
	}

	cin >> S >> E;

	dist[S] = 0;
	shortest.push({ 0, S });

	while(!shortest.empty()) {
		now = shortest.top().second;
		shortest.pop();

		if (now == E)
			break;

		if (processed[now])
			continue;

		processed[now] = true;

		for (pair<int, int> i : city[now]) {
			if (dist[i.first] > dist[now]+i.second) {
				dist[i.first] = dist[now] + i.second;

				shortest.push({ dist[i.first], i.first });	
			}
		}
	}

	cout << dist[E];

	return 0;
}