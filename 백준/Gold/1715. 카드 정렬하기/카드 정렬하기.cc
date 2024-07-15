#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int tmp, result = 0;
	priority_queue<int, vector<int>, greater<int>> card;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		card.push(tmp);
	}

	while (card.size() > 1) {
		tmp = card.top();
		card.pop();
		tmp += card.top();
		card.pop();

		card.push(tmp);
		result += tmp;
	}

	cout << result;

	return 0;
}