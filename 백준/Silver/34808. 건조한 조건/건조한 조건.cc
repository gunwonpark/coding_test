#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;
	
	int n, m, k; cin >> n >> m >> k;

	if (n == 1 && m == 1)
	{
		cout << 0;
		return 0;
	}

	if (n == 1 && m == 2)
	{
		cout << 0 << " " << 0;
		return 0;
	}

	if(n == 2 && m == 1)
	{
		cout << 0 << "\n" << 0;
		return 0;
	}

	if (k == 0 || (n != 1 && m != 1))
	{
		cout << -1;
		return 0;
	}

	

	queue<tuple<int, int, ll>> q;
	q.push({ 0, 0, 0 });
	vector<vector<ll>> visited(n, vector<ll>(m, -1));
	visited[0][0] = 0;
   
	int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		ll value = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + directions[i][0];
			int ny = y + directions[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (visited[nx][ny] == -1) {
					ll new_value = value + k;
					visited[nx][ny] = new_value;
					q.push({ nx, ny, new_value });
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}

    return 0;
}
