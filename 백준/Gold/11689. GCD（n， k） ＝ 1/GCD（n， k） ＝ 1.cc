#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long n, result;

	cin >> n;
	result = n;

	for (long i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			result -= result / i;

			while (n % i == 0)
				n /= i;
		}
	}

	if (n > 1)
		result -= result / n;

	cout << result;

	return 0;
}