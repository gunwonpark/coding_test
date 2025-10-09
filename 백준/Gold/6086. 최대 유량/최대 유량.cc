#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int char_to_int(char c)
{
    if (c >= 'A' && c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}


int main() {
    FAST;

    int n; cin >> n;
	vector<vector<int>> capacity(52, vector<int>(52, 0));
    vector<vector<int>> adj(52);

    for(int i = 0; i < n; i++) {
		char from, to; int cap; cin >> from >> to >> cap;
		int u = char_to_int(from);
		int v = char_to_int(to);
		capacity[u][v] += cap;
		capacity[v][u] += cap;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int source = char_to_int('A');
	int sink = char_to_int('Z');
	int answer = 0;

	while (true)
	{
		vector<int> parent(52, -1);
		queue<int> q;
		q.push(source);
		parent[source] = source;

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			if (cur == sink) break;

			for (int i = 0; i < adj[cur].size(); i++)
			{
				int next = adj[cur][i];
				if (parent[next] != -1 || capacity[cur][next] <= 0) continue;

				parent[next] = cur;
				q.push(next);
			}
		}

		if (parent[sink] == -1) break;

		int min_flow = 1e9;

		for (int i = sink; i != source; i = parent[i])
		{
			min_flow = min(min_flow, capacity[parent[i]][i]);
		}

		for(int i = sink; i != source; i = parent[i])
		{
			capacity[parent[i]][i] -= min_flow;
			capacity[i][parent[i]] += min_flow;
		}

		answer += min_flow;
	}
	
	cout << answer << '\n';

    return 0;
}
