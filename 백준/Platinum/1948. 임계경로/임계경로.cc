#include <bits/stdc++.h>

#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

int main() {
	FAST;

	int n, m, s, e;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, -w });
	}

	cin >> s >> e;

	queue<pair<int,int>> pq;
	vector<int> dist(n + 1, 1e9);
	vector<vector<int>> path(n + 1);

	pq.push({ s, 0 });

	while (!pq.empty()) {
		auto cur = pq.front();
		int curNode = cur.first;
		int curDist = cur.second;

		pq.pop();

		if (dist[curNode] < curDist) continue;

		for (auto next : adj[curNode]) {
			int nextNode = next.first;
			int nextDist = curDist + next.second;
			if (dist[nextNode] > nextDist) {
				dist[nextNode] = nextDist;
				pq.push({ nextNode, nextDist });
				path[nextNode].clear();
				path[nextNode].push_back(curNode);
			}
			else if (dist[nextNode] == nextDist) {
				path[nextNode].push_back(curNode);
			}
		}
	}

	unordered_set<int> visited;

	queue<int> q;
	q.push(e);

	int answer = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (visited.find(cur) != visited.end()) continue;
		visited.insert(cur);
		for (auto prev : path[cur]) {
			q.push(prev);
			answer++;
		}
	}

	cout << -dist[e] << '\n';
	cout << answer << '\n';

    return 0;
}

