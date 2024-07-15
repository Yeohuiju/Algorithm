#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string expression;
	string n;
	vector<int> nums;
	vector<bool> op;
	long result = 0;
	int oidx = 0;
	bool minus = 0;

	cin >> expression;

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] >= '0' && expression[i] <= '9')
			n += expression[i];
		else {
			nums.push_back(stoi(n));
			n = "";

			if (expression[i] == '+')
				op.push_back(1);
			else if (expression[i] == '-')
				op.push_back(0);
		}
	}
	nums.push_back(stoi(n));

	result += nums[0];

	for (int i = 1; i < nums.size(); i++) {
		if (!op[oidx])
			minus = 1;

		if (op[oidx] && !minus) {
			result += nums[i];
			oidx++;
		}
		else {
			result -= nums[i];
			oidx++;
		}
		
	}

	cout << result;

	return 0;
}