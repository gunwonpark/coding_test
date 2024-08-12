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

#define FAST ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;

using namespace std;

struct Command {
	char dir;
	int point;
	string command;

	string print() {
		stringstream ss;
		ss << dir << " " << point << " " << command << "\n";
		return ss.str();
	}
};

int n;
int r, c;

vector<vector<char>> board;

int main() {
	FAST; 	

	cin >> n;
	cin >> r >> c;

	board.resize(n + 1, vector<char>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	vector<Command> cmdList;
	vector<Command> cmdList2;

	// 제일 왼쪽 이동
	for (int i = 1; i < c; i++) {
		Command cmd;
		cmd.dir = 'L';
		cmd.point = r;
		cmd.command = "push";
		cmdList.push_back(cmd);
		cmdList2.push_back(cmd);
	}

	//왼쪽채우기
	for (int i = 1; i < r; i++) {
		Command cmd;
		cmd.dir = 'U';
		cmd.point = 1;
		cmd.command = "push";
		cmdList.push_back(cmd);
		cmdList2.push_back(cmd);
	}
	for (int i = r + 1; i <= n; i++) {
		Command cmd;
		cmd.dir = 'D';
		cmd.point = 1;
		cmd.command = "push";
		cmdList.push_back(cmd);
		cmdList2.push_back(cmd);
	}
	// 위에 채우기
	for (int i = 2; i <= n; i++) {
		Command cmd;
		cmd.dir = 'R';
		cmd.point = 1;
		cmd.command = "push";
		cmdList.push_back(cmd);
		cmdList2.push_back(cmd);
	}
	
	if (r != 1) {
		for (int i = 2; i <= c; i++) {
			Command cmd;
			cmd.dir = 'R';
			cmd.point = r;
			cmd.command = "pull";
			cmdList.push_back(cmd);
			cmdList2.push_back(cmd);
		}
	}

	// 2번째 줄부터 채워보기
	for (int i = 2; i <= n; i++) {
		int lastPos = 1;
		for (int j = 2; j <= n; j++) {
			if (board[i][j] == '#') {
				lastPos = j;
			}
		}
		for (int j = 2; j <= lastPos; j++) {
			Command cmd;
			cmd.dir = 'R';
			cmd.point = i;
			cmd.command = "push";
			cmdList.push_back(cmd);
		}
		for (int j = 2; j <= lastPos; j++) {
			if (board[i][j] == '.') {
				Command cmd;
				cmd.dir = 'D';
				cmd.point = j;
				cmd.command = "pull";
				cmdList.push_back(cmd);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		int lastPos = 1;
		for (int j = 2; j <= n; j++) {
			if (board[j][i] == '#') {
				lastPos = j;
			}
		}
		for (int j = 2; j <= lastPos; j++) {
			Command cmd;
			cmd.dir = 'D';
			cmd.point = i;
			cmd.command = "push";
			cmdList2.push_back(cmd);
		}
		for (int j = 2; j <= lastPos; j++) {
			if (board[j][i] == '.') {
				Command cmd;
				cmd.dir = 'R';
				cmd.point = j;
				cmd.command = "pull";
				cmdList2.push_back(cmd);
			}
		}
	}

	// 왼쪽 벽 확인하기
	for (int i = 1; i <= n; i++) {
		if (board[i][1] == '.') {
			Command cmd;
			cmd.dir = 'L';
			cmd.point = i;
			cmd.command = "pull";
			cmdList.push_back(cmd);
			cmdList2.push_back(cmd);
		}
	}
	// 위 벽 확인하기
	for (int i = 2; i <= n; i++) {
		if (board[1][i] == '.') {
			Command cmd;
			cmd.dir = 'U';
			cmd.point = i;
			cmd.command = "pull";
			cmdList.push_back(cmd);
			cmdList2.push_back(cmd);
		}
	}

	if (cmdList.size() > cmdList2.size()) {
		cmdList = cmdList2;
	}

	cout << cmdList.size() << "\n";
	
	for (auto cmd : cmdList) {
		cout << cmd.print();
	}
	return 0;
}


