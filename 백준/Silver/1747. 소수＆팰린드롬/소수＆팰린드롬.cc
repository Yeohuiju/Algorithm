#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPalin(int a);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	bool nums[10000001];

	nums[0] = false;
	nums[1] = false;
	for (int i = 2; i < 10000001; i++)
		nums[i] = true;

	cin >> n;

	for (int i = 2; i <= 10000001; i++) {
		if (nums[i]) {
			if (i >= n && isPalin(i)) {
				cout << i;

				break;
			}

			for (int j = i + i; j < 10000001; j += i) {
				nums[j] = false;
			}
		}
	}

	return 0;
}

bool isPalin(int a) {
	string num = to_string(a);
	int len = num.length();

	for (int i = 0; i < len / 2; i++) {
		if (num[i] != num[len - i - 1])
			return false;
	}

	return true;
}