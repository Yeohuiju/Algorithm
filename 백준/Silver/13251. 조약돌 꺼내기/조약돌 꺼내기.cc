#include <iostream>
using namespace std;

static int color[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M, K;

	cin >> M;

	for (int i = 1; i <= M; i++) {
		cin >> color[i];
		N += color[i];
	}

	cin >> K;

	cout << fixed;
	cout.precision(9);

	if (M == 1 || K == 1) {
		cout << 1.0;

		return 0;
	}
	
	double result = 0;

	for (int i = 1; i <= M; i++) {
		if (color[i] >= K) {
			double tmp = 1;
			double total = N;

			for (int j = 0; j < K; j++)
				tmp *= color[i]-- / total--;

			result += tmp;
		}
	}

	cout << result;

	return 0;
}