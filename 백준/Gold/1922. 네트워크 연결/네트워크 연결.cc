#include <bits/stdc++.h>

#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

typedef long long ll;

using namespace std;

struct Edge {
	int u, v, dist;

	Edge(int u, int v, int dist) : u(u), v(v), dist(dist) {}

};

struct Compare {
	bool operator()(Edge& a, Edge& b) {
		return a.dist > b.dist;
	}
};


int main() {
	FAST;	
	int N{}, M{}; cin >> N >> M;

	
	vector<Edge> edges;
	vector<vector<pair<int, int>>> adj(N + 1);
	
	priority_queue<Edge, vector<Edge>, Compare> pq;

	for (int i = 0; i < M; i++) {
		int u, v, dist; cin >> u >> v >> dist;
		edges.push_back({u, v, dist});

		adj[u].push_back({ v, dist });
		adj[v].push_back({ u, dist });
	}

	pq.push({ 1, 1, 0 });

	vector<bool> visited(N + 1, false);

	int answer = 0;

	while (!pq.empty()) {
		int prev = pq.top().u;
		int cur = pq.top().v;
		int dist = pq.top().dist;

		pq.pop();

		if (visited[cur]) continue;

		visited[cur] = true;
		answer += dist;

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int nextDist = adj[cur][i].second;
			if (!visited[next]) {
				pq.push({ cur, next, nextDist });
			}
		}
	}
	
	cout << answer << '\n';

	return 0;
}