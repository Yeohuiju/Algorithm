#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int idx;
	int sum = 0;

	cin >> N;
	vector<int> P(N, 0);
	vector<long> S(N + 1, 0);

	for (int i = 0; i < N; i++)
		cin >> P[i];

	for (int i = 1; i < N; i++) {
		int tmp = P[i];
		idx = i;

		for (int j = 0; j < i; j++) {
			if (P[j] > tmp) {
				idx = j;
				break;
			}
		}

		for (int j = i; j > idx; j--)
			P[j] = P[j - 1];

		P[idx] = tmp;
	}

	for (int i = 1; i <= N; i++)
		S[i] = S[i - 1] + P[i - 1];

	for (int i = 1; i <= N; i++)
		sum += S[i];
	
	cout << sum;

	return 0;
}