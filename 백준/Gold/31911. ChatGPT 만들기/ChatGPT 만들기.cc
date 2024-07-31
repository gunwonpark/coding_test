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

ll n, k, m;
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

	result.push_back(start);
	char next = sortedArr[start][0].first;
	start = next;

	ll totalnum = m + k - 1;

	int startChar = sortedArr[start][0].first;

	bool isOne = false;
	bool hasQuery = false;
	int queryStart = 1;
	int queryEnd = 1;
	while (true) {
		result.push_back(start);
		next = sortedArr[start][0].first;

		if (result.size() == totalnum) {
			break;
		}
		if (next == ']') {
			result.push_back(']');
			break;
		}
		if (find(result.begin(), result.end(), next) != result.end()) {
			hasQuery = true;
			queryStart = find(result.begin(), result.end(), next) - result.begin();
			break;
		}
		start = next;
		queryEnd++;
	}

	string resultStr(result.begin(), result.end());
	//여기까지 순환문이나 완성된 결과가 저장되어있다.
	int resultStrSize = resultStr.size();

	string res = "";
	string queryStr = ".";

	if(hasQuery)queryStr = resultStr.substr(queryStart, queryEnd - queryStart + 1);
	
	int querySize = queryStr.size();

	if (k <= resultStrSize) {
		int count = resultStrSize - k + 1;
		if (count >= m) {
			res += resultStr.substr(k - 1, m);
			return 0;
		}
		res += resultStr.substr(k - 1, count);
		m -= count;
		
		int q = m / querySize;
		int r = m % querySize;
		for (int i = 0; i < q; ++i) {
			res += queryStr;
		}
		for (int i = 0; i < r; ++i) {
			res += queryStr[i];
		}
	}
	else {
		ll startPos = k - resultStrSize;

		int q = m / querySize;
		int r = startPos % querySize;
		if(r == 0) r = querySize;
		if (q == 0) {
			if (m + r > querySize) {
				for (int i = r - 1; i < querySize; ++i) {
					res += queryStr[i];
				}
				int temp = querySize - r + 1;
				for (int i = 0; i < temp; ++i) {
					res += queryStr[i];
				}
			}
			else {
				for (int i = r - 1; i < querySize; ++i) {
					res += queryStr[i];
				}
			}
		}
		else {
			for (int i = r - 1; i < querySize; ++i) {
				res += queryStr[i];
			}
			int temp = querySize - r + 1;
			m -= temp;
			q = m / querySize;
			r = m % querySize;

			for (int i = 0; i < q; ++i) {
				res += queryStr;
			}
			for (int i = 0; i < r; ++i) {
				res += queryStr[i];
			}			
		}
	}
	
	cout << res;
	return 0;
}


