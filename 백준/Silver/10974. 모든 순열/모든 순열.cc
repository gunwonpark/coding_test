#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int n;
vector<int> arr;
vector<bool> visited;

void dfs(int cur, int count)
{
	if (count == n)
	{
		for (int i = 0; i < n; i++) {
			cout << arr[i];
			if (i < n - 1) cout << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		arr.push_back(i);
		dfs(i + 1, count + 1);
		visited[i] = false;
		arr.pop_back();
	}
}

int main()
{
	FAST;
	cin >> n;
	visited.resize(n + 1, false);

	dfs(1, 0);

	return 0;
}

