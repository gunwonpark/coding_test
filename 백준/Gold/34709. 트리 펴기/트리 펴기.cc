#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
	FAST;

	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		a[u]++;
		a[v]++;
	}

	int result = 0;

	for (int i = 1; i <= n; i++)
	{
		if (a[i] > 2)
		{
			result += a[i] - 2;
		}
	}

	cout << result;

	return 0;
}
