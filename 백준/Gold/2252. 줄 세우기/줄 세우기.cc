#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int a, b;

	cin >> N >> M;
	vector<vector<int>> students(N + 1);
	vector<int> degree(N + 1, 0);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		students[a].push_back(b);
		degree[b]++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			if (degree[j] == 0) {
				for (int k : students[j])
					degree[k]--;

				cout << j << ' ';
				degree[j] = -1;

				break;
			}
		}
	}

	return 0;
}