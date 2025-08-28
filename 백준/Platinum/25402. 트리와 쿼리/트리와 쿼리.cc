#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

vector<vector<int>> tree;
vector<int> visited;
map<int, int> mp;
int cur_count = 0;


void travel(int node, int q)
{
	cur_count++;
	visited[node] = q;

	for (auto it : tree[node])
	{
		if (visited[it] != q && mp.find(it) != mp.end())
		{
			travel(it, q);
		}
	}
}

int calc(int n)
{
	if (n == 0 || n == 1) return 0;
	return (n * (n - 1)) / 2;
}

int main()
{
	FAST;
	int n; cin >> n;
	tree.resize(n + 1);
	visited.resize(n + 1, 0);

	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	int q; cin >> q;

	while(q--)
	{
		mp.clear();
		ll answer = 0;

		int count; cin >> count;
		for(int i = 0; i < count; i++)
		{
			int node; cin >> node;
			mp[node]++;
		}
		
		for (auto it : mp)
		{
			int node = it.first;
			if (visited[node] == q) continue;
			cur_count = 0;
			travel(node, q);
			answer += calc(cur_count);
		}

		cout << answer << "\n";
	}

	return 0;
}