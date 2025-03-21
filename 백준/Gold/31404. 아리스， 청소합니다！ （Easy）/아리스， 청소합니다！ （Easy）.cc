#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

int visited[64][64][4]{};
bool hasDrt[64][64]{};
int mapA[64][64]{};
int mapB[64][64]{};

int n, m;
int R, C, D;

// 위 오른쪽 아래 왼쪽
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0},{0, -1} };

int SetDir(int curDir, int rotate) {
	curDir += rotate;
	return (curDir % 4);
}

int main() {
	FAST;
	cin >> n >> m;
	cin >> R >> C >> D;

	fill(&visited[0][0][0], &visited[0][0][0] + 64 * 64 * 4, 0);
	fill(&hasDrt[0][0], &hasDrt[0][0] + 64 * 64, true);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			mapA[i][j] = c - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			mapB[i][j] = c - '0';
		}
	}

	int answer = 0;

	vector<bool> tracer;
	queue<tuple<int, int, int, bool ,int>> q;
	q.push({ R, C, SetDir(0, D), true, 1});
	answer = 1;
	hasDrt[R][C] = false;

	while (!q.empty()) {
		auto front = q.front();

		int curR = get<0>(front);
		int curC = get<1>(front);
		int curDir = get<2>(front);
		int deleteDrt = get<3>(front);
		int curMove = get<4>(front);

		q.pop();

		int rotate = 0;

		if (deleteDrt) {
			rotate = mapA[curR][curC];
		}
		else {
			rotate = mapB[curR][curC];
		}

		int nextDir = SetDir(curDir, rotate);

		int nextR = curR + dir[nextDir][0];
		int nextC = curC + dir[nextDir][1];
		int nextMove = curMove + 1;

		if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) continue;
		if (hasDrt[nextR][nextC]) {
			hasDrt[nextR][nextC] = false;
			q.push({ nextR, nextC, nextDir, true, nextMove });
			answer = nextMove;
		}
		else {
			if (visited[nextR][nextC][nextDir] == answer) {
				break;
			}
			
			visited[nextR][nextC][nextDir] = answer;
			q.push({ nextR, nextC, nextDir, false, nextMove });
		}
	}

	cout << answer;
	return 0;
}

