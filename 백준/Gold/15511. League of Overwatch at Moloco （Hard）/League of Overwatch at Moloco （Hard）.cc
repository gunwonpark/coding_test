#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;


vector<set<int>> adj;
vector<int> colored;
bool possible = true;

void dfs(int prev, int cur) {
	if (!possible) return;

	int color = colored[cur];
	for (auto i : adj[cur]) {
		if (i == prev) continue;
		if (colored[i] == -1) {
			colored[i] = 1 - color;
			dfs(cur, i);
		}
		else if (colored[i] == color) {
			possible = false;
			return;
		}
	}
}

int main() {
	FAST;

	int n, k; cin >> n >> k;
	adj.resize(n + 1);
	colored.resize(n + 1, -1);

	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	for (int i = 1; i <= n; i++) {
		if (colored[i] == -1) {
			colored[i] = 1;
			dfs(-1, i);
		}
	}

	if (!possible) cout << "IMPOSSIBLE";
	else cout << "POSSIBLE";

	return 0;
}
