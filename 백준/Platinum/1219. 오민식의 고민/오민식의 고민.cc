#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> edge;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, S, E;
	int s, e, w;

	vector<edge> edges;

	cin >> N >> S >> E >> M;
	vector<long> cost(N, LONG_MIN);
	vector<int> money(N, 0);

	for (int i = 0; i < M; i++) {
		cin >> s >> e >> w;
		edges.push_back(make_tuple(s, e, w));
	}

	for (int i = 0; i < N; i++)
		cin >> money[i];

	cost[S] = money[S];
	long now;

	for (int i = 0; i < N + 50; i++) {
		for (edge j : edges) {
			s = get<0>(j);

			if (cost[s] == LONG_MIN)
				continue;

			e = get<1>(j);
			w = get<2>(j);

			if (cost[s] == LONG_MAX)
				cost[e] = cost[s];
			
			else {
				now = cost[s] + money[e] - w;

				if (cost[e] < now) {
					if (i > N - 1)
						cost[e] = LONG_MAX;
					else
						cost[e] = now;
				}
			}
		}
	}

	if (cost[E] == LONG_MIN)
		cout << "gg";

	else if (cost[E] == LONG_MAX)
		cout << "Gee";

	else
		cout << cost[E];

	return 0;
}