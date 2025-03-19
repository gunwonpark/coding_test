#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

vector<vector<char>> board;
vector<vector<int>> visited;
int maxCount = 0;
int answer = 1e9;
// 0: 오른쪽, 1: 왼쪽, 2: 아래, 3: 위
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

bool check(int x, int y) {
	if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || visited[x][y]) return false;
	return true;
}

void dfs(int x, int y, int d, int count = 1, int result = 1) {
	visited[x][y] = 1;

	if (maxCount == count && answer > result) {
		answer = result;
		visited[x][y] = 0;
		return;
	}

	int nextX = x + dir[d][0];
	int nextY = y + dir[d][1];

	if (check(nextX, nextY) && board[nextX][nextY] != '*') {
		dfs(nextX, nextY, d, count + 1, result);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (i == d) continue;
			nextX = x + dir[i][0];
			nextY = y + dir[i][1];

			if (check(nextX, nextY) && board[nextX][nextY] != '*') {
				dfs(nextX, nextY, i, count + 1, result + 1);
			}
		}
	}
	visited[x][y] = 0;
}

int main() {
	FAST;

	int n, m;
	int t = 1;
	while (cin >> n >> m) {
		board.clear();
		visited.clear();
		maxCount = 0;
		answer = 1e9;

		board.resize(n, vector<char>(m));
		visited.resize(n, vector<int>(m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
				if (board[i][j] == '.') maxCount++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '.') {
					for (int k = 0; k < 4; k++) {
						dfs(i, j, k);
					}
				}
			}
		}

		if (answer == 1e9) answer = -1;
		if (maxCount == 1) answer = 0;

		std::cout << "Case " << t++ << ": " << answer << '\n';
	}
	return 0;
}

