#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <unordered_map>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

vector<vector<char>> arr;
vector<vector<int>> visited;

// 위 아래 오른 왼
int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int result = 0;

enum Directions {
	UP = 0,
	DOWN = 1,
	RIGHT = 2,
	LEFT = 3
};

void travel(int y, int x, int key) {
    visited[y][x] = key;

    Directions dir = Directions::UP;

    if (arr[y][x] == 'U') {
		dir = Directions::UP;
    }
    else if (arr[y][x] == 'D') {
		dir = Directions::DOWN;
    }
    else if (arr[y][x] == 'R') {
		dir = Directions::RIGHT;
    }
    else if (arr[y][x] == 'L') {
		dir = Directions::LEFT;
	}

    int ny = y + direction[dir][0];
    int nx = x + direction[dir][1];

    if (visited[ny][nx]) {
        if (visited[ny][nx] == key) {
            result++;
        }
		return;
    }

    travel(ny, nx, key);
}

int main() {
    FAST;
    int n, m;
    cin >> n >> m;

    arr.resize(n, vector<char>(m));
    visited.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
        for (int j = 0; j < m; j++) {
            arr[i][j] = str[j];
		}
	}

    int key = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                travel(i, j, key++);
            }
		}
	}

    cout << result << '\n';
    return 0;
}