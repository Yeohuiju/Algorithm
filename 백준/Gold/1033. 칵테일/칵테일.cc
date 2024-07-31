#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
    int node;
    int p;
    int q;
} Node;

long gcd(long p, long q);
long lcm(long p, long q);
void dfs(int s);

static vector<vector<Node>> ingre;
static vector<bool> processed;
static vector<long> result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int a, b, p, q;
    long total = 1, part;

    cin >> N;
    ingre.resize(N);
    processed = vector<bool>(N, false);
    result.resize(N);

    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> p >> q;

        ingre[a].push_back(Node{ b, p, q });
        ingre[b].push_back(Node{ a, q, p });

        total *= lcm(p, q);
    }

    result[0] = total;
    dfs(0);

    part = result[0];
    for (long i : result)
        part = gcd(part, i);

    for (int i = 0; i < N; i++) {
        cout << result[i] / part << ' ';
    }

    return 0;
}

long gcd(long p, long q) {
    long a = max(p, q);
    long b = min(p, q);
    long rem;

    while (b != 0) {
        rem = a % b;
        a = b;
        b = rem;
    }

    return a;
}

long lcm(long p, long q) {
    return p * q / gcd(p, q);
}

void dfs(int s) {
    processed[s] = true;

    for (Node i : ingre[s]) {
        if (!processed[i.node]) {
            result[i.node] = result[s] * i.q / i.p;
            dfs(i.node);
        }
    }
}