#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    int max = 0;
    cin >> N;
    vector<pair<int, int>> A(N + 1, { 0, 0 });

    for (int i = 1; i <= N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());
        

    for (int i = 1; i <= N; i++) {
        if (A[i].second - i > max)
            max = A[i].second - i;
    }

    cout << max + 1;

	return 0;
}