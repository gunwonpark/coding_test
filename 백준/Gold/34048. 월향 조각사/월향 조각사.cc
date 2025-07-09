#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main()
{
	FAST;

	int n; cin >> n;
	vector<int> arr(n + 2);
	arr[0] = 0;
	arr[n + 1] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	vector<int> l_dp(n + 2, 1);
	vector<int> r_dp(n + 2, 1);

	l_dp[0] = 0;
	l_dp[n + 1] = 0;

	r_dp[0] = 0;
	r_dp[n + 1] = 0;

	int cur_max = 1;

	for (int i = 1; i <= n; i++)
	{
		int cur = arr[i];
		int left = arr[i - 1];

		if (cur >= cur_max && left >= cur_max - 1)
		{
			l_dp[i] = cur_max;
			cur_max++;
		}
		else
		{
			l_dp[i] = cur;
			cur_max = cur + 1;
		}
	}

	cur_max = 1;

	for (int i = n; i >= 1; i--)
	{
		int cur = arr[i];
		int right = arr[i + 1];
		if (cur >= cur_max && right >= cur_max - 1)
		{
			r_dp[i] = cur_max;
			cur_max++;
		}
		else
		{
			r_dp[i] = cur;
			cur_max = cur + 1;
		}
	}

	ll answer = 0;

	for (int i = 1; i <= n; i++)
	{
		int cur = min(l_dp[i], r_dp[i]);

		answer += cur;
	}

	cout << answer;

	return 0;
}

