#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& a, vector<int>& b);
void quickSelect(vector<int>& arr, int s, int e, int k);
int partition(vector<int>& arr, int s, int e);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	int pivot;

	cin >> N >> K;
	vector<int> A(N, 0);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	quickSelect(A, 0, N - 1, K - 1);
	
	cout << A[K - 1];
	
	return 0;
}

void swap(vector<int>& a, vector<int>& b) {
	int tmp = a[0];

	a[0] = b[0];
	b[0] = tmp;
}

void quickSelect(vector<int>& arr, int s, int e, int k) {
	int pivot = partition(arr, s, e);

	if (pivot == k)
		return;

	else if (k < pivot)
		quickSelect(arr, s, pivot - 1, k);

	else
		quickSelect(arr, pivot + 1, e, k);
}

int partition(vector<int>& arr, int s, int e) {
	if (e - s == 1) {
		if (arr[s] > arr[e])
			swap(arr[s], arr[e]);
		return s;
	}

	int m = (s + e) / 2;
	swap(arr[s], arr[m]);

	int pivot = arr[s];
	int i = s + 1, j = e;

	while (i <= j) {
		while (j > s && arr[j] > pivot)
			j--;
			
		while (i <= e && arr[i] < pivot)
			i++;

		if (i < j)
			swap(arr[i++], arr[j--]);
		else
			break;
	}

	swap(arr[s], arr[j]);

	return j;
}