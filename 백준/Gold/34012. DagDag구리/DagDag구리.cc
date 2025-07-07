#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main()
{
	FAST;

	int n, m; cin >> n >> m;

	map<int, int> outdegree;
	set<int> nodes;
	int E = 0;

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		outdegree[u]++;
		nodes.insert(u);
		nodes.insert(v);
	}

	for (auto& node : nodes) {
		if (outdegree[node] == 0) {
			E = node;
			break;
		}
	}

	int answer = 0;

	for (auto& node : nodes)
	{
		if (node == E) continue;
		if (outdegree[node] == 1)
		{
			answer++;
		}
	}

	cout << answer;
	
	return 0;
}

