#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& a, vector<int>& b) {
	int tmp = a[0];

	a[0] = b[0];
	b[0] = tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	int max;
	vector<int> nums;
	cin >> N;

	for (int i = 0; i < N.length(); i++)
		nums.push_back(N[i] - '0');

	for (int i = 0; i < nums.size(); i++) {
		max = nums[i];

		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[j] > max) {
				swap(nums[i], nums[j]);
				max = nums[i];
			}
		}
		cout << nums[i];
	}

	return 0;
}