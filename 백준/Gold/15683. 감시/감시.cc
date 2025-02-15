#include <bits/stdc++.h>

#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

typedef long long ll;

using namespace std;

struct Camera {
	int x, y, type;

	Camera(int x, int y, int type) : x(x), y(y), type(type) {}
};

int N{}, M{};

vector<vector<char>> board;
vector<vector<int>> counter;
vector<Camera> cameras;

int answer = 1e9;

void fill_X_right(int x, int y, bool reverse) {
	for (int i = y + 1; i < M; i++) {
		if (board[x][i] == '6') break;
		if (board[x][i] == '0' || board[x][i] == '#') {
			if (reverse) {
				counter[x][i]--;
				if (counter[x][i] == 0) board[x][i] = '0';
			}
			else {
				counter[x][i]++;
				board[x][i] = '#';
			}
		}
	}
}

void fill_X_left(int x, int y, bool reverse) {
	for (int i = y - 1; i >= 0; i--) {
		if (board[x][i] == '6') break;
		if (board[x][i] == '0' || board[x][i] == '#') {
			if (reverse) {
				counter[x][i]--;
				if (counter[x][i] == 0) board[x][i] = '0';
			}
			else {
				counter[x][i]++;
				board[x][i] = '#';
			}
		}
	}
}

void fill_Y_up(int x, int y, bool reverse) {
	for (int i = x - 1; i >= 0; i--) {
		if (board[i][y] == '6') break;
		if (board[i][y] == '0' || board[i][y] == '#') {
			if (reverse) {
				counter[i][y]--;
				if (counter[i][y] == 0) board[i][y] = '0';
			}
			else {
				counter[i][y]++;
				board[i][y] = '#';
			}
		}
	}
}

void fill_Y_down(int x, int y, bool reverse) {
	for (int i = x + 1; i < N; i++) {
		if (board[i][y] == '6') break;
		if (board[i][y] == '0' || board[i][y] == '#') {
			if (reverse) {
				counter[i][y]--;
				if (counter[i][y] == 0) board[i][y] = '0';
			}
			else {
				counter[i][y]++;
				board[i][y] = '#';
			}
		}
	}
}

void fill_X(int x, int y, bool reverse) {
	fill_X_right(x, y, reverse);
	fill_X_left(x, y, reverse);
}

void fill_Y(int x, int y, bool reverse) {
	fill_Y_up(x, y, reverse);
	fill_Y_down(x, y, reverse);
}

void fill_board(int x, int y, int type, int dir, bool reverse) {
	switch (type) {
	case 1:
		switch (dir) {
		case 0:
			fill_X_right(x, y, reverse);
			break;
		case 1:
			fill_Y_up(x, y, reverse);
			break;
		case 2:
			fill_X_left(x, y, reverse);
			break;
		case 3:
			fill_Y_down(x, y, reverse);
			break;
		}
		break;
	case 2:
		switch (dir) {
		case 0:
		case 2:
			fill_X(x, y, reverse);
			break;
		case 1:
		case 3:
			fill_Y(x, y, reverse);
			break;
		}
		break;
	case 3:
		switch (dir) {
		case 0:
			fill_Y_up(x, y, reverse);
			fill_X_right(x, y, reverse);
			break;
		case 1:
			fill_X_right(x, y, reverse);
			fill_Y_down(x, y, reverse);
			break;
		case 2:
			fill_Y_down(x, y, reverse);
			fill_X_left(x, y, reverse);
			break;
		case 3:
			fill_X_left(x, y, reverse);
			fill_Y_up(x, y, reverse);
			break;
		}
		break;
	case 4:
		switch (dir) {
		case 0:
			fill_Y_up(x, y, reverse);
			fill_X_right(x, y, reverse);
			fill_X_left(x, y, reverse);
			break;
		case 1:
			fill_X_right(x, y, reverse);
			fill_Y_down(x, y, reverse);
			fill_Y_up(x, y, reverse);
			break;
		case 2:
			fill_Y_down(x, y, reverse);
			fill_X_left(x, y, reverse);
			fill_X_right(x, y, reverse);
			break;
		case 3:
			fill_X_left(x, y, reverse);
			fill_Y_up(x, y, reverse);
			fill_Y_down(x, y, reverse);
			break;
		}
		break;
	case 5:
		fill_X(x, y, reverse);
		fill_Y(x, y, reverse);
		break;
	}
}

void dfs(int depth) {
	if (depth == cameras.size()) {
		//사각지대 계산
		int temp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == '0') temp++;
			}
		}
		answer = min(answer, temp);
		return;
	}

	int curX = cameras[depth].x;
	int curY = cameras[depth].y;
	int curType = cameras[depth].type;

	for (int i = 0; i < 4; i++) 
	{
		fill_board(curX, curY, curType, i, false);
		dfs(depth + 1);
		fill_board(curX, curY, curType, i, true);
	}
}



int main() {
	FAST;	

	cin >> N >> M;

	board.resize(N, vector<char>(M, 0));
	counter.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] >= '1' && board[i][j] <= '5') {
				cameras.push_back({ i, j, board[i][j] - '0'});
			} 
		}
	}

	dfs(0);

	cout << answer << '\n';

	return 0;
}