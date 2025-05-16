#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

vector<vector<char>> board;
int n;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void bfs(int x, int y, char key, char target)
{
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dir[i][0];
		int nextY = y + dir[i][1];

		if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
		
		
		if (board[nextX][nextY] == key)
		{
			board[nextX][nextY] = target;
			bfs(nextX, nextY, key, target);
		}
	}
}

int main()
{
	FAST;

	cin >> n; 

	board.resize(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int fa = 0;
	int sa = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'R')
			{
				board[i][j] = '1';
				bfs(i, j, 'R', '1');
				fa++;
			}
			else if (board[i][j] == 'G')
			{
				board[i][j] = '1';
				bfs(i, j, 'G', '1');
				fa++;
			}
			else if(board[i][j] == 'B')
			{
				board[i][j] = '2';
				bfs(i, j, 'B', '2');
				fa++;
			}
		}
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '1')
			{
				board[i][j] = '-';
				bfs(i, j, '1', '-');
				sa++;
			}
			else if (board[i][j] == '2')
			{
				board[i][j] = '-';
				bfs(i, j, '2', '-');
				sa++;
			}
		}
	}

	cout << fa << " " << sa;
	return 0;
}

