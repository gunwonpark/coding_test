#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int n;
set<pair<int, int>> connections;
vector<vector<int>> adj;

pair<int, int> findDepthTwo(int node)
{
	for(int i = 0; i < adj[node].size(); i++)
	{
		int child = adj[node][i];

		for(int j = 0; j < adj[child].size(); j++)
		{
			int grandChild = adj[child][j];
			if (grandChild != node)
			{
				return { child, grandChild };
			}
		}
	}

	return { -1, -1 };
}

int main() {
    FAST;

    cin >> n;
	adj.resize(n + 1);

	int hasThreeChild = -1;

    for (int i = 1; i < n; i++) {
        int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
        adj[v].push_back(u);
		connections.insert({ u, v });
		connections.insert({ v, u });

		if (adj[u].size() >= 3)
		{
			hasThreeChild = u;
		}

		if (adj[v].size() >= 3)
		{
			hasThreeChild = v;
		}
	}

	cout << 3 << '\n';

	if (hasThreeChild != -1)
	{
		int child1 = adj[hasThreeChild][0];
		int child2 = adj[hasThreeChild][1];
		int child3 = adj[hasThreeChild][2];

		cout << child1 << ' ' << child2 << '\n';
		cout << child2 << ' ' << child3 << '\n';
		cout << child3 << ' ' << child1 << '\n';
	}
	else
	{
		int key = 1;
		pair<int, int> firstTwo = findDepthTwo(key);
		pair<int, int> secondTwo = findDepthTwo(firstTwo.first);

		cout << key << ' ' << firstTwo.second << '\n';
		cout << firstTwo.first << ' ' << secondTwo.second << '\n';

		int key1 = firstTwo.second;
		int key2 = secondTwo.second;
		
		if(connections.find({key, key2}) == connections.end() || connections.find({key2, key}) == connections.end())
		{
			cout << key << ' ' << key2 << '\n';
		}
		else
		{
			cout << key1 << ' ' << key2 << '\n';
		}
	}

    return 0;
}
