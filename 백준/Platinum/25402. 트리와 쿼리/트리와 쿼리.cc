#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

vector<vector<int>> tree;
vector<int> visited;
vector<int> group_value;
vector<int> parent;
vector<int> group;

int find(int n)
{
	if (group[n] == n) return n;
	return group[n] = find(group[n]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b) return;

	group_value[a] += group_value[b];
	group[b] = a;
	group_value[b] = 0;
}

void calc_parent(int current, int parentIdx)
{
	parent[current] = parentIdx;

	for(int i = 0; i < tree[current].size(); i++)
	{
		int next = tree[current][i];
		if (next == parentIdx) continue;
		calc_parent(next, current);
	}
}



int calc(int n)
{
	return (n * (n - 1)) / 2;
}

int main()
{
	FAST;
	int n; cin >> n;
	tree.resize(n + 1);
	visited.resize(n + 1, 0);
	group_value.resize(n + 1, 0);
	parent.resize(n + 1, 0);
	group.resize(n + 1, 0);

	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	calc_parent(1, 1);

	int q; cin >> q;
	while(q--)
	{
		int count; cin >> count;
		vector<int> nodes(count);
		for(int i = 0; i < count; i++)
		{
			cin >> nodes[i];
			group_value[nodes[i]] = 1;
			visited[nodes[i]] = q;
			group[nodes[i]] = nodes[i];
		}

		for (int i = 0; i < count; i++)
		{
			int current = nodes[i];
			if (visited[parent[current]] != q) continue;

			merge(current, parent[current]);
		}

		ll answer = 0;
		for(int i = 0; i < count; i++)
		{
			int root = find(nodes[i]);
			if (group_value[root] > 0)
			{
				answer += calc(group_value[root]);
				group_value[root] = 0;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}