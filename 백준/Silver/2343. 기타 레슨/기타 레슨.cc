#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int sum = 0, max = 0;
	int median, idx = 0;
	
	cin >> N >> M;
	vector<int> time(N, 0);
	vector<long> bluRay(M, 0);

	for (int i = 0; i < N; i++) {
		cin >> time[i];
		sum += time[i];

		if (time[i] > max)
			max = time[i];
	}

	while (max <= sum) {
		median = (max + sum) / 2;

		for (int i : bluRay) {
			while (i < median && idx < N)
				i += time[idx++];

			if (i > median)
				i -= time[--idx];
		}

		if (idx < N)
			max = median + 1;
		else
			sum = median - 1;

		idx = 0;
		fill(bluRay.begin(), bluRay.end(), 0);
	}
		
	cout << max;

	return 0;
}