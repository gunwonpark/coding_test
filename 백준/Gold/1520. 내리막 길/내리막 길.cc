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

int col, row;
vector<vector<int>> arr;
vector<vector<int>> dp;
vector<vector<bool>> visited;

vector<pair<int, int>> dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int dfs(int _col, int _row) {
	if (_col == col - 1 && _row == row - 1) {
		return 1;
	}

	if(dp[_col][_row] != -1) return dp[_col][_row];

	dp[_col][_row] = 0;

	for (int i = 0; i < dir.size(); ++i) {
		int next_col = _col + dir[i].first;
		int next_row = _row + dir[i].second;
		if (next_col >= 0 && next_col < col && next_row >= 0 && next_row < row && arr[next_col][next_row] < arr[_col][_row]) {
			dp[_col][_row] += dfs(next_col, next_row);
		}
	}

	return dp[_col][_row];
}

int main() {
	FAST;

	
	cin >> col >> row;

	arr.resize(col, vector<int>(row, 0));
	visited.resize(col, vector<bool>(row, false));
	dp.resize(col, vector<int>(row, -1));

	for(int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			cin >> arr[i][j];

	dfs(0, 0);

	cout << dp[0][0];
	return 0;
}


