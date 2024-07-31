#include <iostream>
#include <vector>
using namespace std;

static vector<int> people;
static vector<vector<int>> party;

void Union(int a, int b);
int Find(int x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int count, know, person;
	bool check = false;
	int result = 0;

	cin >> N >> M;
	people.resize(N + 1);
	party.resize(M);

	for (int i = 1; i <= N; i++)
		people[i] = i;


	cin >> count;

	if (count) {
		cin >> know;

		for (int i = 1; i < count; i++) {
			cin >> person;
			Union(know, person);
		}
	}
	else
		result = M;

	for (int i = 0; i < M; i++) {
		cin >> count >> person;
		party[i].push_back(person);

		for (int j = 1; j < count; j++) {
			cin >> person;
			party[i].push_back(person);

			Union(party[i][j - 1], person);
		}
	}

	if (!result) {
		know = Find(know);
		for (int i = 0; i < M; i++) {
			if (Find(party[i][0]) != know)
				result++;
		}
	}

	cout << result;

	return 0;
}

void Union(int a, int b) {
	int repr1 = Find(a);
	int repr2 = Find(b);

	if (repr1 != repr2)
		people[repr2] = repr1;
}

int Find(int x) {
	if (people[x] == x)
		return x;

	else {
		people[x] = Find(people[x]);
		return people[x];
	}
}