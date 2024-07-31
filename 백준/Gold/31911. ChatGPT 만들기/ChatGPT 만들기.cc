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

int n, k, m;
map<char,map<char, int>> arr;


int main() {
	FAST;

	// 1. 입력 받기
	cin >> n >> k >> m;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		for (int j = 1; j < s.size(); ++j) {
			int prev = s[j - 1];
			int cur = s[j];

			arr[prev][cur]++;
		}
	}
	
	map<char, vector<pair<char, int>>> sortedArr;

	for (auto& outerPair : arr) {
		vector<pair<char, int>> innerVec(outerPair.second.begin(), outerPair.second.end());

		sort(innerVec.begin(), innerVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
			if (a.second == b.second) return a.first < b.first;
			return a.second > b.second;
			});

		sortedArr[outerPair.first] = innerVec;
	}

	vector<char> result;
	
	char start = '[';
	int count = 0;

	ll totalnum = m + k - 1;

	while (true) {
		result.push_back(start);
		char next = sortedArr[start][0].first;

		if (result.size() == totalnum) {
			break;
		}
		if (next == ']') {
			result.push_back(']');
			break;
		}

		start = next;
	}

	string add = "";
	
	if (result.size() < totalnum) {
		add = string(totalnum - result.size(), '.');
	}
	string resultStr(result.begin(), result.end());
	
	string newString = resultStr + add;

	cout << newString.substr(k - 1, totalnum);
	return 0;
}


