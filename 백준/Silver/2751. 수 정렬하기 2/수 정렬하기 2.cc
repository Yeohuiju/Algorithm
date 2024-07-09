#include <iostream>
#include <vector>
using namespace std;

static vector<int> A;
static vector<int> tmp;

void mergeSort(int s, int e);
void merge(int s1, int s2, int e);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;
	A = vector<int>(N, 0);
	tmp = vector<int>(N, 0);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	mergeSort(0, N - 1);

	for (int i = 0; i < N; i++)
		cout << A[i] << '\n';

	return 0;
}

void mergeSort(int s, int e) {
	if (s >= e)
		return;

	int m = (s + e) / 2;

	mergeSort(s, m);
	mergeSort(m + 1, e);
	merge(s, m + 1, e);
}

void merge(int s1, int s2, int e) {
	int i = s1, j = s2, idx = s1;

	for (int k = s1; k <= e; k++)
		tmp[k] = A[k];

	while (i < s2 && j <= e) {
		if (tmp[i] <= tmp[j])
			A[idx++] = tmp[i++];
		else
			A[idx++] = tmp[j++];
	}

	if (i == s2) {
		for (int k = j; k <= e; k++)
			A[idx++] = tmp[k];
	}
	else
		for (int k = i; k < s2; k++)
			A[idx++] = tmp[k];
}