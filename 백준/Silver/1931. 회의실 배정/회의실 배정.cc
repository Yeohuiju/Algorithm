#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<long, long> a, pair<long, long> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int start, end;
	int result = 0;

	cin >> N;
	vector<pair<long, long>> meet;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		meet.push_back({ start, end });
	}

	sort(meet.begin(), meet.end(), cmp);

	start = meet[0].first;
	end = meet[0].second;
	result++;

	for (int i = 1; i < N; i++) {
		if (meet[i].first >= end) {
			end = meet[i].second;
			result++;
		}
	}

	cout << result;

	return 0;
}