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

int n, m, d;
vector<int> s;
vector<vector<int>> board;
vector<vector<int>> temp;

int result = 0;

int dir[3][2] = { {0, -1}, {-1, 0}, {0, 1} };

pair<int, int> kill(int pos) {
	int x = pos;
	int y = n - 1;

	if (temp[y][x] == 1) {		
		return { y, x };
	}

	queue<pair<int, int>> q;
	vector<vector<int>> visit(n, vector<int>(m, 0));
	q.push({ y, x });
	visit[y][x] = 1;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		if (abs(x - pos) + abs(y - (n - 1)) >= d - 1) return { -1, -1 };

		for (int i = 0; i < 3; i++) {
			int nx = x + dir[i][1];
			int ny = y + dir[i][0];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (visit[ny][nx] == 1) continue;

			if (temp[ny][nx] == 1) {
				return { ny, nx };
			}

			q.push({ ny, nx });
			visit[ny][nx] = 1;
			
		}
	}

	return { -1, -1 };
}

void Next() {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = temp[i - 1][j];
		}
	}
	for(int i = 0; i < m; i++) temp[0][i] = 0;
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << temp[i][j] << " ";
		}
		cout << "\n";
	}
}

void sol() {
	temp = board;

	

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		set<pair<int, int>> se;
		for (int j = 0; j < 3; j++) {
			pair<int, int> p = kill(s[j]);
			if (p.first != -1) se.insert(p);
		}
		cnt += se.size();
		for (auto it = se.begin(); it != se.end(); it++) {
			temp[it->first][it->second] = 0;
		}
		Next();	
	}

	result = max(result, cnt);
}

void combination(int iter) {
	if (s.size() == 3) {
		sol();
	}

	for (int i = iter; i < m; i++) {
		s.push_back(i);
		combination(i + 1);
		s.pop_back();
	}
}


int main() {
	Fast;

	cin >> n >> m >> d;

	board.resize(n, vector<int>(m));
	temp.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	combination(0);


	cout << result << "\n";
	return 0;
	
}