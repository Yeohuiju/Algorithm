#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tmp1, tmp2;
	int zero = 0;
	long sum = 0;

	priority_queue<int> plus;
	priority_queue<int, vector<int>, greater<int>> minus;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp1;

		if (tmp1 > 1)
			plus.push(tmp1);
		else if (tmp1 < 0)
			minus.push(tmp1);
		else if (tmp1 == 1)
			sum++;
		else
			zero++;
	}

	while (plus.size() > 1) {
		tmp1 = plus.top();
		plus.pop();
		tmp2 = plus.top();
		plus.pop();

		sum += tmp1 * tmp2;
	}
	if (!plus.empty())
		sum += plus.top();

	while (minus.size() > 1) {
		tmp1 = minus.top();
		minus.pop();
		tmp2 = minus.top();
		minus.pop();

		sum += tmp1 * tmp2;
	}
	if (!minus.empty() && !zero)
		sum += minus.top();

	cout << sum;

	return 0;
}