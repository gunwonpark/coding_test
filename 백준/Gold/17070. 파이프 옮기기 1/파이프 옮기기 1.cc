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

struct Node {
	int y, x, dir;
	Node(int a, int b, int c) : y(a), x(b), dir(c) {}
};

int n;
int board[17][17];
int dir[3][2] = { {0,1},{1,0},{1,1} };
int result = 0;
//대각선일시 오른 아래 대각선 이동가능
//가로일시 가로 대각선 이동가능
//세로일시 세로 대각선 이동가능
void sol() {
	queue<Node> q;
	q.push({ 1, 2, 0 });

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int _dir = q.front().dir;
		q.pop();

		for (int i = 0; i < 3; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if(_dir == 0 && i == 1)
				continue;
			if (_dir == 1 && i == 0)
				continue;
			if (ny < 1 || nx < 1 || ny > n || nx > n)
				continue;

			if (i == 0) {
				if (board[y][x + 1] == 1)
					continue;
			}
			else if (i == 1) {
				if (board[y + 1][x] == 1)
					continue;
			}
			else if (i == 2) {
				if (board[y + 1][x + 1] == 1 || board[y][x + 1] == 1 || board[y + 1][x] == 1)
					continue;
			}

			if (ny == n && nx == n) {
				result++;
				continue;
			}

			q.push({ ny,nx,i });
		}
	}
	
}
int main() {
	Fast;

	cin >> n;

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	

	sol();

	cout << result << "\n";
	return 0;
	
}