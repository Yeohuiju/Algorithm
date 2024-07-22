#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, A, B;
	int a, b, rem;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;

		a = max(A, B);
		b = min(A, B);

		while (b != 0) {
			rem = a % b;
			a = b;
			b = rem;
		}

		cout << A * B / a << "\n";
	}

	return 0;
}