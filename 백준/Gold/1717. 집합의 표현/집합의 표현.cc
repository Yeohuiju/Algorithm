#include <iostream>
#include <vector>
using namespace std;

static vector<int> group;

void Union(int a, int b);
int Find(int x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	bool op;
	int a, b;

	cin >> n >> m;
	group = vector<int>(n + 1);

	for (int i = 0; i <= n; i++)
		group[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> op >> a >> b;

		if (op) {
			if (Find(a) == Find(b))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		else
			Union(a, b);
	}

	return 0;
}

void Union(int a, int b) {
	int repr1 = Find(a);
	int repr2 = Find(b);

	group[repr1] = repr2;
}

int Find(int x) {
	if (group[x] == x)
		return x;
	else {
		group[x] = Find(group[x]);
		return group[x];
	}
}