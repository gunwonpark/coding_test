#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;



int main() {
	FAST;

	int n, k; cin >> n >> k;
	int visited[100001];

	fill(visited, visited + 100001, -1);
	queue<pair<int, int>> q;
	q.push({n, 1});
	visited[n] = n;
	while (!q.empty()) {
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();

		if (pos == k) {
			break;
		}

		int next[] = { pos - 1, pos + 1, pos * 2 };

		for (int i = 0; i < 3; i++) {
			int nextPos = next[i];
			if (nextPos < 0 || nextPos > 100000 || visited[nextPos] != - 1) continue;
			visited[nextPos] = pos;
			q.push({ nextPos, time + 1 });
		}
	}

	vector<int> path;
	int cur = k;
	while (cur != n) {
		path.push_back(cur);
		cur = visited[cur];
	}

	cout << path.size() << '\n';

	path.push_back(n);
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << ' ';
	}
	
	return 0;
}