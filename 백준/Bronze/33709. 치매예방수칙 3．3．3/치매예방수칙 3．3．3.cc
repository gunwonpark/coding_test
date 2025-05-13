#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

vector<string> split(const char* str, const char* delimeter) {
	vector<string> tokens;
	char* str_copy = strdup(str);
	char* token = strtok(str_copy, delimeter);

	while (token != nullptr) {
		tokens.push_back(token);
		token = strtok(nullptr, delimeter);
	}

	return tokens;
}

int main()
{
	FAST;
	
	int n; cin >> n;
	string input; cin >> input;

	vector<string> tokens = split(input.data(), ".|:#");
	int answer = 0;
	for (int i = 0; i < tokens.size(); i++) {
		int num = stoi(tokens[i]);
		answer += num;
	}

	cout << answer;



	return 0;
}

