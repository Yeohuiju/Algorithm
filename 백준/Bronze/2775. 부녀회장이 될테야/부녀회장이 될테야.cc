#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	int house[15][15];

	for (int i = 0; i < 15; i++) {
		house[0][i] = i;
		house[i][1] = 1;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 2; j < 15; j++)
			house[i][j] = house[i][j - 1] + house[i - 1][j];
	}

	cin >> T;

	for (int t = 0; t < T; t++) {
		int k, n;
		cin >> k >> n;

		cout << house[k][n] << "\n";
	}

	return 0;
}