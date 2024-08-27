#include <iostream>
using namespace std;

class Node {
public:
	Node* next[26];
	bool isEnd;

	Node() : isEnd(false) {
		fill(next, next + 26, nullptr);
	}

	~Node() {
		for (auto& child : next)
			delete child;
	}

	void insert(const char* key) {
		if (*key == 0)
			isEnd = true;
		else {
			int nextIdx = *key - 'a';

			if (next[nextIdx] == nullptr)
				next[nextIdx] = new Node();

			next[nextIdx]->insert(key + 1);
		}
	}

	Node* find(const char* key) {
		if (*key == 0)
			return this;

		int nextIdx = *key - 'a';

		if (next[nextIdx] == nullptr)
			return nullptr;

		return next[nextIdx]->find(key + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	Node* root = new Node();

	for (int i = 0; i < N; i++) {
		char text[501];
		cin >> text;

		root->insert(text);
	}

	int count = 0;
	for (int i = 0; i < M; i++) {
		char text[501];
		cin >> text;

		Node* result = root->find(text);

		if (result && result->isEnd)
			count++;
	}

	cout << count;
	

	return 0;
}