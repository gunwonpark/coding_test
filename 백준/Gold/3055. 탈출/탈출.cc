#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

struct Node {
	int x, y, cnt;
	Node() {
		x = 0;
		y = 0;
		cnt = 0;
	}
	Node(int y, int x, int cnt) {
		this->y = y;
		this->x = x;
		this->cnt = cnt;
	}
};

int r, c;
// 0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<vector<char>> board;
queue<Node> waterPos;
queue<Node> hedgehogPos;
// 고슴도치의 방문 경로 파악
vector<vector<bool>> visited;
// 비버의 초기 위치 저장
pair<int, int> beaverPos;

void bfs() {

	int result = 0;
	// 고슴도치가 비버의 칸으로 도달하기 전에 끝나면 "KAKTUS" 출력
	while (!hedgehogPos.empty()) {
		//한 단계만 물 차오르기
		while (!waterPos.empty()) {
			int y = waterPos.front().y;
			int x = waterPos.front().x;
			int cnt = waterPos.front().cnt;
			if (cnt != result) {
				break;
			}
			waterPos.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
					continue;
				}

				//이미 물이 차있는곳 비버의 집, 돌이 있는 곳은 물이 차지 않는다
				if(board[ny][nx] == '*' || board[ny][nx] == 'X' || board[ny][nx] == 'D')
					continue;

				board[ny][nx] = '*';
				waterPos.push({ny, nx, cnt + 1});
			}
		}

		//고슴도치 이동
		while (!hedgehogPos.empty()) {
			int y = hedgehogPos.front().y;
			int x = hedgehogPos.front().x;
			int cnt = hedgehogPos.front().cnt;

			if (cnt != result) {
				break;
			}

			hedgehogPos.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
					continue;
				}

				//비버의 집에 도착하였다면 결과 출력
				if (ny == beaverPos.first && nx == beaverPos.second) {
					cout << cnt + 1 << endl;
					return;
				}

				//이미 방문했던곳은 방문할 필요가 없고 물이 차있는곳, 돌이 있는곳은 갈 수 없다
				if (visited[ny][nx] || board[ny][nx] == '*' || board[ny][nx] == 'X') {
					continue;
				}


				visited[ny][nx] = true;
				hedgehogPos.push({ny, nx, cnt + 1});
			}
		}
		
		//다음 단계 진입
		result++;
	}

	cout << "KAKTUS" << endl;
}

int main() {    
	cin >> r >> c;
	board.resize(r, vector<char>(c));
	visited.resize(r, vector<bool>(c, false));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == '*') {
				waterPos.push({i, j, 0});
			}
			else if (board[i][j] == 'S') {
				hedgehogPos.push({i, j, 0});
				visited[i][j] = true;
			}
			else if (board[i][j] == 'D') {
				beaverPos = {i, j};
			}
		}
	}

	bfs();
    return 0;
}