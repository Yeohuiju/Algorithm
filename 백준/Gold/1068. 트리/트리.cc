#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> tree;
static vector<bool> visited;
static int d, result;

void deleteNode(int s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, root;
	cin >> N;

	tree.resize(N);
	visited.resize(N, false);

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		
		if (n != -1) {
			tree[i].push_back(n);
			tree[n].push_back(i);
		}
		else
			root = i;
	}

	result = 0;

	cin >> d;

	if (d == root)
		cout << 0;
	else {
		deleteNode(root);
		cout << result;
	}

	return 0;
}

void deleteNode(int s) {
	visited[s] = true;
	bool leaf = true;

	for (int i : tree[s]) {
		if (!visited[i] && i != d) {
			leaf = false;
			deleteNode(i);
		}
	}

	if (leaf)
		result++;
}