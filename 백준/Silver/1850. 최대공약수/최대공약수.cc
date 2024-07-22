#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long  A, B;
	long long a, b, rem;

	cin >> A >> B;

	a = max(A, B);
	b = min(A, B);

	while (b != 0) {
		rem = a % b;
		a = b;
		b = rem;
	}

	for (long long i = 0; i < a; i++)
		cout << '1';

	return 0;
}