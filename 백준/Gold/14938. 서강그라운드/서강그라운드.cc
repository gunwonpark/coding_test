#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

int main() {
	FAST;

	int n, m, r; cin >> n >> m >> r;
	vector<vector<int>> adj;
	adj.resize(n + 1, vector<int>(n + 1, 1e9));

	for (int i = 1; i <= n; i++) {
		adj[i][i] = 0;
	}

	vector<int> items(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> items[i];
	}

	for (int i = 0; i < r; i++) {
		int u, v, dist; cin >> u >> v >> dist;
		adj[u][v] = dist;
		adj[v][u] = dist;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}

	int max_items = 0;

	for (int i = 1; i <= n; i++) {
		int cur_items = 0;
		int cur_area = i;
		for (int j = 1; j <= n; j++) {
			int next_area = j;
			if (adj[cur_area][next_area] <= m) {
				cur_items += items[next_area];
			}
		}

		max_items = max(max_items, cur_items);
	}

	cout << max_items << endl;
    return 0;
}