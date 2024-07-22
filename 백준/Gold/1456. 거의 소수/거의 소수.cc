#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long A, B;
	long result = 0, tmp;
	bool nums[10000001];
	
	nums[0] = false;
	nums[1] = false;
	for (long i = 2; i < 10000001; i++)
		nums[i] = true;

	cin >> A >> B;

	for (long i = 2; i <= sqrt(B); i++) {
		if (nums[i]) {
			tmp = i;

			while ((double)i <= (double)B / (double)tmp) {
				if ((double)i >= (double)A / (double)tmp) {
					result++;
				}
				tmp *= i;
			}

			for (long j = i * 2; j < min(sqrt(B) + 1, (double)10000001); j += i) {
				if (nums[j])
					nums[j] = false;
			}
		}
	}

	cout << result;

	return 0;
}