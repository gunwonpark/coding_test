#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

vector<int> ans;
vector<vector<int>> board;
int bSize;

int groupID;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int counts = 0;

void travel(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx < 0 || ny < 0 || nx >= bSize || ny >= bSize) continue;
		if (board[nx][ny] == 1) {
			board[nx][ny] = 0;
			counts++;
			travel(nx, ny);
		}
	}
}

int main() {
	FAST;
	cin >> bSize;

	for (int i = 0; i < bSize; i++) {
		vector<int> temp;
		string s; cin >> s;
		for (int j = 0; j < bSize; j++) {
			temp.push_back(s[j] - '0');
		}
		board.push_back(temp);
	}

	for (int i = 0; i < bSize; i++) {
		for (int j = 0; j < bSize; j++) {
			if (board[i][j] == 1) {
				counts = 1;
				board[i][j] = 0;
				travel(i, j);
				ans.push_back(counts);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

    return 0;
}