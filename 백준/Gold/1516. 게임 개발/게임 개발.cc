#include <iostream>
#include <vector>
#include <deque>
using namespace std;

static vector<int> Time;
static vector<vector<int>> prior;
vector<int> result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int input, now;

	cin >> N;
	Time.resize(N + 1);
	prior.resize(N + 1);
	result.resize(N + 1, 0);
	vector<int> indegree(N + 1, 0);
	deque<int> tmp;
	deque<int> order;
	
	for (int i = 1; i <= N; i++) {
		cin >> Time[i];

		cin >> input;

		while (input > 0) {
			prior[i].push_back(input);
			indegree[input]++;

			cin >> input;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			tmp.push_back(i);
	}

	while (!tmp.empty()) {
		now = tmp.front();
		tmp.pop_front();
		order.push_front(now);

		for (int i : prior[now]) {
			indegree[i]--;

			if (indegree[i] == 0)
				tmp.push_back(i);
		}
	}

	while (!order.empty()) {
		now = order.front();
		order.pop_front();

		result[now] = Time[now];
		input = 0;
		
		for (int i : prior[now])
			input = max(input, result[i]);

		result[now] += input;
	}

	for (int i = 1; i <= N; i++)
		cout << result[i] << "\n";

	return 0;
}