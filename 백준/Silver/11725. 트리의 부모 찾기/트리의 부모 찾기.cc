#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> tree;
static vector<int> parent;

void findParent(int p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	tree.resize(N + 1);
	parent.resize(N + 1, 0);

	for (int i = 1; i < N; i++) {
		int e1, e2;
		cin >> e1 >> e2;
		
		tree[e1].push_back(e2);
		tree[e2].push_back(e1);
	}

	parent[1] = 1;
	findParent(1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";

	return 0;
}

void findParent(int p) {
	for (int i : tree[p]) {
		if (!parent[i]) {
			parent[i] = p;
			findParent(i);
		}
	}
}