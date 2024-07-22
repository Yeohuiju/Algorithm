#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long min, max;
	long result = 0, square, idx;

	cin >> min >> max;

	vector<bool> noSquare(max - min + 1, true);

	for (long i = 2; i * i <= max; i++) {
		square = i * i;
		idx = min / square;

		if (min % square)
			idx++;

		for (long j = idx; square * j <= max; j++) {
			noSquare[square * j - min] = false;
		}
	}

	for (bool i : noSquare) {
		if (i)
			result++;
	}

	cout << result;

	return 0;
}