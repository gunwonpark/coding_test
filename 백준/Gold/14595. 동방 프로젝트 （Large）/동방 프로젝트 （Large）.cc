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

int n, m;
vector<int> arr;
vector<pair<int, int>> range;

int Solution() {
	int result = range[0].first - 1;

	int left = range[0].first;
	int right = range[0].second;

	for (int i = 1; i < range.size(); ++i){
		if (range[i].first <= right) {
			if(range[i].second > right) right = range[i].second;
		}
		else {
			result += range[i].first - right;

			left = range[i].first;
			right = range[i].second;
		}
	}
	
	result += n - right + 1;

	return result;
}


int main() {
	FAST;

	// 1. 입력 받기
	cin >> n >> m;

	arr.resize(n);
	range.resize(m);

	for (int i = 0; i < m; i++) {
		cin >> range[i].first >> range[i].second;
	}

	sort(range.begin(), range.end(), [](pair<int, int>& a, pair<int, int>& b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first < b.first;
		});

	if (m == 0) {
		cout << n;
	}
	else
	{
		cout << Solution();
	}

	
	return 0;
}


