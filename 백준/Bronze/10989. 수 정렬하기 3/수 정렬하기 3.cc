#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tmp;
	int A[10001] = { 0 };

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		A[tmp]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < A[i]; j++)
			cout << i << '\n';
	}

	return 0;
}