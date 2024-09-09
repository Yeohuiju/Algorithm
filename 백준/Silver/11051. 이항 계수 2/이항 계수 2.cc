#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	int comb[1001][1001];

	cin >> N >> K;

	
	for (int i = 0; i <= N; i++) {
		comb[i][0] = 1;
		comb[i][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < min(i, K + 1); j++)
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % 10007;
	}

	cout << comb[N][K];

	return 0;
}