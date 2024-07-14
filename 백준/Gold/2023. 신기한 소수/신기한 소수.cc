#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

static int N;
static vector<int> nums;

void makeNum(int n);
bool isPrime(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	makeNum(2);
	makeNum(3);
	makeNum(5);
	makeNum(7);
	
	for (int i : nums)
		cout << i << "\n";

	return 0;
}

void makeNum(int n) {
	if (to_string(n).length() == N) {
		nums.push_back(n);
		return;
	}

	for (int i = 10 * n; i < 10 * (n + 1); i++) {
		if (isPrime(i))
			makeNum(i);
	}
}

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}