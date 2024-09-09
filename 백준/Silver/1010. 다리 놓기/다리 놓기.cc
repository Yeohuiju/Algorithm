#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	int bridge[30][30];

	for (int i = 0; i < 30; i++) {
		bridge[i][0] = 1;
		bridge[i][i] = 1;
	}

	for (int i = 2; i < 30; i++) {
		for (int j = 1; j < i; j++)
			bridge[i][j] = bridge[i - 1][j] + bridge[i - 1][j - 1];
	}

	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		cout << bridge[M][N] << "\n";
	}

	return 0;
}