#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

int main() {
	Fast;

	int n;
	cin >> n;
	
	ll reuslt = 0;
	int board[100][100] = { 0, };
	ll dp[100][100] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if(board[i][j] == 0) continue;

			int nextX = j + board[i][j];
			int nextY = i + board[i][j];

			if((nextX == n - 1 && i == n - 1)) dp[i][j] = 1;
			if((nextY == n - 1 && j == n - 1)) dp[i][j] = 1;

			if(nextX < n && dp[i][nextX] != 0) dp[i][j] += dp[i][nextX];
			if(nextY < n && dp[nextY][j] != 0) dp[i][j] += dp[nextY][j];
		}
	}

	cout << dp[0][0] << endl;

	return 0;
}

