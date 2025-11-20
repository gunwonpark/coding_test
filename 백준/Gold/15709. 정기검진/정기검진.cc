#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
	FAST;

	int n, m, b, k, q; cin >> n >> m >> b >> k >> q;

	vector<vector<pair<int, ll>>> arr(n + m + b + 1);

	for (int i = 0; i < k; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		arr[a].push_back({ b, c });
		arr[b].push_back({ a, c });
	}
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	vector<vector<ll>> dist(b, vector<ll>(n + m + b + 1, 1e18));

	for (int i = 0; i < b; i++)
	{
		dist[i][n + m + i + 1] = 0;
		pq.push({ 0, n + m + i + 1 });
		while (!pq.empty())
		{
			pair<ll, int> cur = pq.top();
			pq.pop();

			for (int j = 0; j < arr[cur.second].size(); j++)
			{
				pair<int, ll> next = arr[cur.second][j];
				if (next.second + cur.first < dist[i][next.first])
				{
					dist[i][next.first] = next.second + cur.first;
					pq.push({ dist[i][next.first], next.first });
				}
			}
		}
	}


	while (q--)
	{
		int s, e; cin >> s >> e;
		ll ans = 1e18;
		for (int i = 0; i < b; i++)
		{
			ans = min(ans, dist[i][s] + dist[i][e]);
		}

		if(ans == 1e18) cout << -1 << "\n";
		else cout << ans << "\n";
	}

	return 0;
}
