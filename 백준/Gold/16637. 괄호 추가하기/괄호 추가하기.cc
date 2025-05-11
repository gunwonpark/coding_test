#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int maxCount = 0;
vector<char> ops;
vector<int> contents;

ll answer = -2147483647563;

ll calc(ll a, ll b, char op)
{
	if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else if (op == '*') {
		return a * b;
	}
	else if (op == '/') {
		return a / b;
	}
	else {
		return 0;
	}
}

void solve(int index, vector<int> values, vector<char> operators, bool isPass)
{
	if (index == maxCount) {
		ll result = values[0];
		
		for (int i = 0; i < values.size() - 1; i++) {
			char op = operators[i];
			int value = values[i + 1];
			
			result = calc(result, value, op);
			
		}

		answer = max(answer, result);
		return;
	}

	if (!values.empty()) {
		int value = values.back();
		char op = operators.back();

		int curValue = contents[index];

		int result = calc(value, curValue, op);

		
		// 그냥 보내는 경우
		
		values.push_back(curValue);
		if (ops.size() > index)
			operators.push_back(ops[index]);

		solve(index + 1, values, operators, false);
		values.pop_back();
		if (ops.size() > index)
			operators.pop_back();
		

		if (isPass) {
			return;
		}

		values.pop_back();
		operators.pop_back();
		// 계산 후 보내는 경우
		
		values.push_back(result);
		if (ops.size() > index)
			operators.push_back(ops[index]);

		solve(index + 1, values, operators, true);
	}
	else {
		values.push_back(contents[index]);
		if(ops.size() > 0)
			operators.push_back(ops[index]);
		solve(index + 1, values, operators, false);
	}
}

int main()
{
	FAST;
	int n; cin >> n;
	maxCount = n / 2 + 1;

	string input; cin >> input;

	for (int i = 0; i < n; i += 2) {
		string temp = input.substr(i, 2);
		contents.push_back(stoi(temp.substr(0, 1)));

		if (i + 1 < n) {
			ops.push_back(temp[1]);
		}
	}
	
	solve(0, {}, {}, false);
	cout << answer << '\n';

	return 0;
}



