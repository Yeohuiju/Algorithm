#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sender[6] = { 0, 0, 1, 1, 2, 2 };
	int receiver[6] = { 1, 2, 0, 2, 0, 1 };

	int water[3];
	int now[3];
	int s, r, move;
	bool processed[201][201] = { };

	queue<pair<int, int>> cases;
	priority_queue<int, vector<int>, greater<int>> result;

	cin >> water[0] >> water[1] >> water[2];

	cases.push({ 0, 0 });
	result.push(water[2]);
	processed[0][0] = 1;

	while (!cases.empty()) {
		for (int i = 0; i < 6; i++) {
			now[0] = cases.front().first;
			now[1] = cases.front().second;
			now[2] = water[2] - now[0] - now[1];

			s = sender[i];
			r = receiver[i];

			if (now[s] > 0) {
				move = min(water[r] - now[r], now[s]);
				now[r] += move;
				now[s] -= move;

				if (!processed[now[0]][now[1]]) {
					processed[now[0]][now[1]] = 1;
					cases.push({ now[0], now[1] });

					if (!now[0])
						result.push(water[2] - now[1]);
				}
			}
		}
		cases.pop();
	}

	while (!result.empty()) {
		cout << result.top() << ' ';
		result.pop();
	}

	return 0;
}