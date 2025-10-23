#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;


int main() {
    FAST;
	int n, m, s, t; cin >> n >> m >> s >> t;
	vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 1e18));

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		ll w; cin >> w;

		dist[u][v] = min(dist[u][v], w);
	}

	for(int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int q; cin >> q;

	while (q--)
	{
		ll t1, t2;
		int u1, v1; cin >> u1 >> v1;
		ll dist1; cin >> dist1;
		int u2, v2; cin >> u2 >> v2;
		ll dist2; cin >> dist2;

		t1 = dist[u1][v1];
		t2 = dist[u2][v2];

		dist[u1][v1] = min(dist[u1][v1], dist1);
		dist[u2][v2] = min(dist[u2][v2], dist2);

		ll result = min(dist[s][t], dist[s][u1] + dist[u1][v1] + dist[v1][t]);
		result = min(result, dist[s][u2] + dist[u2][v2] + dist[v2][t]);
		result = min(result, dist[s][u1] + dist[u1][v1] + dist[v1][u2] + dist[u2][v2] + dist[v2][t]);
		result = min(result, dist[s][u2] + dist[u2][v2] + dist[v2][u1] + dist[u1][v1] + dist[v1][t]);
		
		if(result == 1e18) {
			cout << -1 << "\n";
		} else {
			cout << result << "\n";
		}

		dist[u1][v1] = t1;
		dist[u2][v2] = t2;
	}
  

    return 0;
}
