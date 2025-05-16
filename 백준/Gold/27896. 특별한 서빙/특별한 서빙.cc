#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main()
{
	FAST;

	int n; cin >> n;
	ll m; cin >> m;

	vector<ll> satisfy = vector<ll>(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> satisfy[i];
	}
	
	priority_queue<ll> q;

	int answer = 0;
	ll dissatisfy = 0;

	for (int i = 0; i < n; i++)
	{
		ll cur = satisfy[i];

		if (dissatisfy + cur < m)
		{
			dissatisfy += cur;
			q.push(cur);
		}
		else if (!q.empty() && q.top() > cur)
		{
			ll val = q.top();
			q.pop();

			dissatisfy -= val * 2;
			dissatisfy += cur;
			q.push(cur);
			answer++;
		}
		else
		{
			dissatisfy -= cur;
			answer++;
		}
	}

	cout << answer;

	return 0;
}

