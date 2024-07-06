#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &arr, int idx1, int idx2) {
	int tmp = arr[idx1];

	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int end = 1;

	cin >> N;
	vector<int> nums(N, 0);
	int last = N;

	for (int i = 0; i < N; i++)
		cin >> nums[i];
	
	while (end) {
		end = 0;
		
		for (int i = 1; i < last; i++) {
			if (nums[i - 1] > nums[i]) {
				swap(nums, i - 1, i);
				end++;
			}
		}

		last--;
	}

	for (int i = 0; i < N; i++)
		cout << nums[i] << "\n";

	return 0;
}
