#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	int result = 0, tmp;

	cin >> N >> K;
	vector<int> coin(N, 0);

	for (int i = 0; i < N; i++)
		cin >> coin[i];

	for (int i = N - 1; i >= 0; i--) {
		tmp = K / coin[i];
		result += tmp;
		K -= coin[i] * tmp;

		if (K == 0)
			break;
	}

	cout << result;

	return 0;
}