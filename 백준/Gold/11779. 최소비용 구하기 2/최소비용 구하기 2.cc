#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

struct Node {
	int end, cost;
	Node(int end, int cost) : end(end), cost(cost) {}
};

int n, m;
vector<vector<Node>> arr;
vector<pair<int, int>> dist;

int main() {
	Fast;

	cin >> n >> m;
	arr.resize(n + 1);
	dist.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		arr[start].push_back(Node(end, cost));
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = { 1e9, i };
	}

	int start, end;
	cin >> start >> end;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = { 0, 0 };
	
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;

		if (cur == end) {
			cout << dist[cur].first << "\n";
			stack<int> s;
			while (cur != 0) {
				s.push(cur);
				cur = dist[cur].second;
			}
			cout << s.size() << "\n";
			while (!s.empty()) {
				cout << s.top() << " ";
				s.pop();
			}
			return 0;
		}

		pq.pop();


		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].end;
			int nextCost = cost + arr[cur][i].cost;


			if (dist[next].first <= nextCost) continue;

			pq.push({ -nextCost, next });

			dist[next].first = nextCost;
			dist[next].second = cur;
		}
	}

	return 0;
	
}