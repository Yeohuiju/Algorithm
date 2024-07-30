#include <iostream>
#include <vector>
using namespace std;

static vector<int> path;

void Union(int a, int b);
int Find(int x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	bool road, result = true;
	int travel, start;

	cin >> N >> M;
	path.resize(N + 1);

	for (int i = 1; i <= N; i++)
		path[i] = i;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> road;
			if (road)
				Union(i + 1, j + 1);
		}
	}

	cin >> start;
	start = Find(start);
	for (int i = 1; i < M; i++) {
		cin >> travel;
		
		travel = Find(travel);

		if (start != travel) {
			result = false;
			break;
		}			
	}

	if (result)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}

void Union(int a, int b) {
	int repr1 = Find(a);
	int repr2 = Find(b);

	if (repr1 != repr2)
		path[repr1] = repr2;
}

int Find(int x) {
	if (path[x] == x)
		return x;

	else {
		path[x] = Find(path[x]);
		return path[x];
	}
}