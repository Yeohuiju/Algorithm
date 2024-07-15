#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<int> num;

int binarySearch(int t, int s, int e);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;;

	cin >> N;
	num.resize(N, 0);

	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num.begin(), num.end());

	cin >> M;
	vector<int>target(M, 0);

	for (int i = 0; i < M; i++)
		cin >> target[i];

	for (int i : target)
		cout << binarySearch(i, 0, N) << "\n";

	return 0;
}

int binarySearch(int t, int s, int e) {
	if (s >= e || e > num.size())
		return 0;

	int m = (s + e) / 2;
	int median = num[m];

	if (median == t)
		return 1;
	else if (t < median)
		return binarySearch(t, s, m);
	else if (t > median)
		return binarySearch(t, m + 1, e);
}