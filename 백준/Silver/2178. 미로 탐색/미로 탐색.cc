#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> Node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string tmp;
	int count = 0;
	queue<Node> node;

	cin >> N >> M;
	vector<vector<int>> maze(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		cin >> tmp;

		for (int j = 0; j < M; j++) {
			if (tmp[j] - '0')
				maze[i][j] = 1;
		}
	}

	node.push({ 0, 0 });
	maze[0][0] = 0;
	count++;

	while (true) {
		Node n = node.front();
		node.pop();

		if (n == Node(N - 1, M - 1))
			break;

		int i = n.first, j = n.second;

		if (i - 1 >= 0 && maze[i - 1][j] > 0) {
			maze[i - 1][j] = maze[i][j] - 1;
			node.push({ i - 1, j });
		}

		if (j - 1 >= 0 && maze[i][j - 1] > 0) {
			maze[i][j - 1] = maze[i][j] - 1;
			node.push({ i, j - 1});
		}

		if (j + 1 < M && maze[i][j + 1] > 0) {
			maze[i][j + 1] = maze[i][j] - 1;
			node.push({ i, j + 1 });
		}

		if (i + 1 < N && maze[i + 1][j] > 0) {
			maze[i + 1][j] = maze[i][j] - 1;
			node.push({ i + 1, j });
		}

		if(maze[node.front().first][node.front().second] < maze[i][j])
			count++;
	}

	cout << count;

	return 0;
}