#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	int a, b, c;
	int update;
	pair<int, int> now;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> shortest;

	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> city(n + 1);
	vector<priority_queue<int>> dist(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		city[a].push_back({ b, c });
	}

	dist[1].push(0);
	shortest.push({ 0, 1 });

	while (!shortest.empty()) {
		now = shortest.top();
		shortest.pop();

		for (pair<int, int> i : city[now.second]) {
			update = now.first + i.second;

			if (dist[i.first].size() < k) {
				dist[i.first].push(update);
				shortest.push({ update, i.first });
			}
			else if (dist[i.first].top() > update) {
				dist[i.first].pop();
				dist[i.first].push(update);
				shortest.push({ update, i.first });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() == k)
			cout << dist[i].top() << "\n";
		else
			cout << -1 << "\n";
	}

	return 0;
}