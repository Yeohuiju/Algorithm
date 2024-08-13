#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;
typedef tuple<int, int, int> edge;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int s, e, w;
	bool minus = false;

	vector<edge> bus;

	cin >> N >> M;
	vector<long> dist(N + 1, LONG_MAX);
	dist[1] = 0;

	for (int i = 0; i < M; i++) {
		cin >> s >> e >> w;
		bus.push_back(make_tuple(s, e, w));
	}

	for (int i = 1; i < N; i++) {
		for (edge j : bus) {
			s = get<0>(j);

			if (dist[s] == LONG_MAX)
				continue;

			e = get<1>(j);
			w = get<2>(j);

			if (dist[e] > dist[s] + w)
				dist[e] = dist[s] + w;
		}
	}

	for (int i = 1; i < N; i++) {
		for (edge j : bus) {
			s = get<0>(j);

			if (dist[s] == LONG_MAX)
				continue;

			e = get<1>(j);
			w = get<2>(j);

			if (dist[e] > dist[s] + w) {
				minus = true;
				break;
			}
		}

		if (minus)
			break;
	}

	if (minus)
		cout << -1;

	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == LONG_MAX)
				cout << -1 << "\n";
			else
				cout << dist[i] << "\n";
		}
	}

	return 0;
}