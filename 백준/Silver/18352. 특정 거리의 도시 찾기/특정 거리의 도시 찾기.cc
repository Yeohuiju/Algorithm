#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K, X;
	int c1, c2;
	queue<int> node;
	vector<int> result;

	cin >> N >> M >> K >> X;
	vector<vector<int>> city(N + 1, vector<int>());
	vector<int> check(N + 1, -1);

	for (int i = 0; i < M; i++) {
		cin >> c1 >> c2;

		city[c1].push_back(c2);
	}

	for (int i = 1; i <= N; i++)
		sort(city[i].begin(), city[i].end());

	check[X] = 0;
	node.push(X);
	while (!node.empty()) {
		int tmp = node.front();
		node.pop();

		for (int i : city[tmp]) {
			if (check[i] == -1) {
				check[i] = check[tmp] + 1;
				node.push(i);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == K)
			result.push_back(i);
	}

	if (result.empty())
		cout << -1;
	else {
		for (int i : result)
			cout << i << "\n";
	}

	return 0;
}