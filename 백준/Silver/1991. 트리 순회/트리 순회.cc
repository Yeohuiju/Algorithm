#include <iostream>
#include <vector>
using namespace std;

static int tree[26][2];
static vector<int> result;
static int N;

void preorder(int s);
void inorder(int s);
void postorder(int s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		char node, c1, c2;
		int idx;
		cin >> node >> c1 >> c2;

		idx = node - 'A';

		if (c1 != '.')
			tree[idx][0] = c1 - 'A';
		else
			tree[idx][0] = -1;
			
		if (c2 != '.')
			tree[idx][1] = c2 - 'A';
		else
			tree[idx][1] = -1;
	}

	preorder(0);
	for (int i = 0; i < N; i++)
		cout << (char)(result[i] + 'A');
	cout << "\n";
	result.clear();

	inorder(0);
	for (int i = 0; i < N; i++)
		cout << (char)(result[i] + 'A');
	cout << "\n";
	result.clear();

	postorder(0);
	for (int i = 0; i < N; i++)
		cout << (char)(result[i] + 'A');
	
	return 0;
}

void preorder(int s) {
	if (s == -1)
		return;

	result.push_back(s);
	preorder(tree[s][0]);
	preorder(tree[s][1]);
}

void inorder(int s) {
	if (s == -1)
		return;

	inorder(tree[s][0]);
	result.push_back(s);
	inorder(tree[s][1]);
}

void postorder(int s) {
	if (s == -1)
		return;

	postorder(tree[s][0]);
	postorder(tree[s][1]);
	result.push_back(s);
}