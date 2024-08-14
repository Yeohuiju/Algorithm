#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;
	vector<vector<int>> bacon(N + 1, vector<int>(N + 1, INT_MAX));

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		bacon[a][b] = 1;
		bacon[b][a] = 1;
	}

	for (int i = 1; i <= N; i++)
		bacon[i][i] = 0;

	for (int k = 1; k <= N; k++) {
		for (int s = 1; s <= N; s++) {
			for (int e = s + 1; e <= N; e++) {
				if (bacon[s][k] + bacon[k][e] > 0) {
					bacon[s][e] = min(bacon[s][e], bacon[s][k] + bacon[k][e]);
					bacon[e][s] = bacon[s][e];
				}
			}
		}
	}

	int minIdx = -1;
	int min = INT_MAX;
	int sum;

	for (int i = 1; i <= N; i++){
		sum = 0;

		for (int j = 1; j <= N; j++)
			sum += bacon[i][j];
		
		if (sum < min) {
			minIdx = i;
			min = sum;
		}
	}

	cout << minIdx;

	return 0;
}