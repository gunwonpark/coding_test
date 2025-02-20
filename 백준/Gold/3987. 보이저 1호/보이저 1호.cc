#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;
int n, m;
vector<vector<char>> board;
int visited[501][501][4];

int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

char SwitchDir(char c, char key) {
	if (key == '\\') {
		switch (c) {
		case 'U': return 'L';
		case 'D': return 'R';
		case 'L': return 'U';
		case 'R': return 'D';
		}
	}
	else if (key == '/') {
		switch (c) {
		case 'U': return 'R';
		case 'D': return 'L';
		case 'L': return 'D';
		case 'R': return 'U';
		}
	}

	return c;
}

int SwitchDir(char c) {
	switch (c) {
	case 'U': return 0;
	case 'R': return 1;
	case 'D': return 2;
	case 'L': return 3;
	}

	return -1;
}

int answer = 0;
char canswer = 'U';
bool isInf = false;
char cInf = 'U';

void Travel(int curx, int cury, char curDir, int length, char startDir) {
	if (visited[curx][cury][SwitchDir(curDir)] == 1) {
		if(!isInf)
			cInf = startDir;
		isInf = true;
		return;
	}

	visited[curx][cury][SwitchDir(curDir)] = 1;

	int nextx = curx + dir[SwitchDir(curDir)][0];
	int nexty = cury + dir[SwitchDir(curDir)][1];

	if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m || board[nextx][nexty] == 'C') {
		if (answer < length) {
			answer = length;
			canswer = startDir;
		}

		visited[curx][cury][SwitchDir(curDir)] = 0;
		return;
	}


	if (board[nextx][nexty] == '\\') {
		char dir = SwitchDir(curDir, '\\');
		Travel(nextx, nexty, dir, length + 1, startDir);
	}
	else if (board[nextx][nexty] == '/') {
		char dir = SwitchDir(curDir, '/');
		Travel(nextx, nexty, dir, length + 1, startDir);
	}
	else if (board[nextx][nexty] == '.') {
		Travel(nextx, nexty, curDir, length + 1, startDir);
	}

	visited[curx][cury][SwitchDir(curDir)] = 0;
}

int main() {
    FAST;

	cin >> n >> m;

	board.resize(n, vector<char>(m));
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int x, y; cin >> x >> y;

	x--;
	y--;
	Travel(x, y, 'U', 1, 'U');
	Travel(x, y, 'R', 1, 'R');
	Travel(x, y, 'D', 1, 'D');
	Travel(x, y, 'L', 1, 'L');

	if (isInf) {
		cout << cInf << '\n';
		cout << "Voyager";
	}
	else {
		cout << canswer << '\n' << answer;
	}

    return 0;
}