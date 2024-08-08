#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>
#include <string>
#include <map>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;

string str;
string cmp_str;

struct info {
	int index;
	char c;
};

int main() {
	FAST; 	

	cin >> str >> cmp_str;

	int index = 0;
	int cmp_index = 0;
	stack<info> s;
	vector<int> cmp_value;
	cmp_value.resize(str.length());
	while (index < str.length()) {
		if (str[index] == cmp_str[cmp_index]) {
			cmp_value[index] = ++cmp_index;
		}
		else {
			cmp_index = 0;
			if (str[index] == cmp_str[cmp_index]) {
				cmp_value[index] = ++cmp_index;
			}
		}

		s.push({ index, str[index] });
		index++;

		if (cmp_index == cmp_str.length()) {
			for (int i = 0; i < cmp_str.length(); i++)
				s.pop();
			if (!s.empty()) {
				cmp_index = cmp_value[s.top().index];
			}
			else {
				cmp_index = 0;
			}
		}
	}

	if (s.empty()) {
		cout << "FRULA";
	}
	else {
		string result = "";
		while (!s.empty()) {
			result += s.top().c;
			s.pop();
		}
		reverse(result.begin(), result.end());
		cout << result;
	}

	return 0;
}


