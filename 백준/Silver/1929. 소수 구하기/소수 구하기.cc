#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;

	cin >> M >> N;
	vector<int> nums(N + 1, 0);

	for (int i = 2; i <= N; i++)
		nums[i] = i;

	for (int i = 2; i <= sqrt(N); i++) {
		if (nums[i]) {
			for (int j = i * 2; j <= N; j += i) {
				if (nums[j])
					nums[j] = 0;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (nums[i])
			cout << nums[i] << "\n";	
	}

	return 0;
}