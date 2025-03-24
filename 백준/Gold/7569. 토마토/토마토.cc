#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

struct pos {
	int x, y, z;
};;


bool visited[101][101][101]{};

int main() {
	FAST;

	int n, m; cin >> m >> n;
	int h; cin >> h;

	vector<vector<vector<int>>> arr(h, vector<vector<int>>(n, vector<int>(m, 0)));

	queue<pos> q;
	

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push({ i, j, k });
					visited[i][j][k] = true;
				}
			}
		}
	}

	int dx[] = { 0, 0, 1, -1, 0, 0 };
	int dy[] = { 1, -1, 0, 0, 0, 0 };
	int dz[] = { 0, 0, 0, 0, 1, -1 };

	while (!q.empty()) {
		pos cur = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nz = cur.z + dz[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
			if (visited[nx][ny][nz] || arr[nx][ny][nz] != 0) continue;
			visited[nx][ny][nz] = true;
			arr[nx][ny][nz] = arr[cur.x][cur.y][cur.z] + 1;
			q.push({ nx, ny, nz });
		}
	}

	int ans = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				ans = max(ans, arr[i][j][k]);
			}
		}
	}

	cout << ans - 1;
	return 0;
}
