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

struct Ball {
	int mass;
	int speed;
	int dir;

	Ball(int mass, int speed, int dir) : mass(mass), speed(speed), dir(dir) {}
};

int dirX[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dirY[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int n, m, k;
vector<vector<vector<Ball>>> board;

void MoveBall() {
	vector<vector<vector<Ball>>> newBoard(n + 1, vector<vector<Ball>>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int size = board[i][j].size();
			
			for (int k = size - 1; k >= 0; k--) {
				int mass = board[i][j][k].mass;
				int speed = board[i][j][k].speed;
				int dir = board[i][j][k].dir;

				board[i][j].pop_back();

				int nx = j + dirX[dir] * speed;
				int ny = i + dirY[dir] * speed;

				if (nx < 1) nx = n - abs(nx) % n;
				if (ny < 1) ny = n - abs(ny) % n;
				if (nx > n) nx = nx % n;
				if (ny > n) ny = ny % n;
				if (nx == 0) nx = n;
				if (ny == 0) ny = n;

				newBoard[ny][nx].push_back(Ball(mass, speed, dir));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < newBoard[i][j].size(); k++) {
				board[i][j].push_back(newBoard[i][j][k]);
			}
		}
	}
}

void MergeBall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j].size() > 1) {
				int totalMass = 0;
				int totalSpeed = 0;
				int odd = 0;
				int even = 0;

				int boardSize = board[i][j].size();

				for (int k = boardSize - 1; k >= 0; k--) {
					totalMass += board[i][j][k].mass;
					totalSpeed += board[i][j][k].speed;

					if (board[i][j][k].dir % 2 == 0) even++;
					else odd++;

					board[i][j].pop_back();
				}

				int newMass = totalMass / 5;
				int newSpeed = totalSpeed / boardSize;

				if (newMass == 0) continue;

				if (even == boardSize || odd == boardSize) {
					for (int k = 0; k < 4; k++) {
						board[i][j].push_back(Ball(newMass, newSpeed, k * 2));
					}
				}
				else {
					for (int k = 0; k < 4; k++) {
						board[i][j].push_back(Ball(newMass, newSpeed, k * 2 + 1));
					}
				}
			}
		}
	}
}

int main() {
	Fast;
	cin >> n >> m >> k;

	board.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		board[i].resize(n + 1);
	}
	

	for (int i = 1; i <= m; i++) {
		int y, x, mass, speed, dir;
		cin >> y >> x >> mass >> speed >> dir;

		board[y][x].push_back(Ball(mass, speed, dir));
	}

	for (int i = 0; i < k; i++) {
		MoveBall();
		MergeBall();
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < board[i][j].size(); k++) {
				answer += board[i][j][k].mass;
			}
		}
	}

	cout << answer << "\n";

	return 0;
	
}