#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
	FAST;
	int priority[4];

	for (int i = 0; i < 4; i++)
	{
		cin >> priority[i];
	}

	unordered_map<string, int> op_priority = {
		{"+", priority[0]},
		{"-", priority[1]},
		{"*", priority[2]},
		{"/", priority[3]}
	};

	string origin; cin >> origin;

	string temp = "";
	vector<string> tokens;

	for (int i = 0; i < origin.size(); i++)
	{
		if(origin[i] == '+' || origin[i] == '-' || origin[i] == '*' || origin[i] == '/')
		{
			tokens.push_back(temp);
			temp = "";
			tokens.push_back(string(1, origin[i]));
			continue;
		}

		temp += origin[i];
	}

	tokens.push_back(temp);

	reverse(tokens.begin(), tokens.end());

	queue<string> q;
	stack<string> s;

	for (int i = 0; i < tokens.size(); i++)
	{
		if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
		{
			while(!s.empty() && op_priority[s.top()] >= op_priority[tokens[i]])
			{
				q.push(s.top());
				s.pop();
			}
			s.push(tokens[i]);
		}
		else
		{
			q.push(tokens[i]);
		}
	}

	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}

	stack<ll> result_stack;
	result_stack.push(stoll(q.front()));
	q.pop();

	while (!q.empty())
	{
		string token = q.front();
		q.pop();

		if(token == "+" || token == "-" || token == "*" || token == "/")
		{
			ll operand2 = result_stack.top();
			result_stack.pop();
			ll operand1 = result_stack.top();
			result_stack.pop();

			ll result;
			if(token == "+")
			{
				result = operand1 + operand2;
			}
			else if(token == "-")
			{
				result = operand1 - operand2;
			}
			else if(token == "*")
			{
				result = operand1 * operand2;
			}
			else if(token == "/")
			{
				result = operand1 / operand2;
			}
			result_stack.push(result);
		}
		else
		{
			result_stack.push(stoll(token));
		}
	}

	cout << result_stack.top() << "\n";

	return 0;
}
