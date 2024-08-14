#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

static vector<vector<long>> cost;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;
	cost.resize(n + 1);
	fill(cost.begin(), cost.end(), vector<long>(n + 1, LONG_MAX));

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		if (cost[a][b] > c)
			cost[a][b] = c;
	}

	for (int i = 1; i <= n; i++)
		cost[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (cost[s][k] + cost[k][e] >= 0)
					cost[s][e] = min(cost[s][e], cost[s][k] + cost[k][e]);
			}
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == LONG_MAX)
				cout << 0 << ' ';
			else
				cout << cost[i][j] << ' ';
		}

		cout << "\n";
	}

	return 0;
}