#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int n, m, k, t;
// a번째 시간에 b명친구들이 남았을 경우
int dp[302][302][302];
int cur_count[302];

int travel(int day, int count, int friend_count)
{
	if (day == n + 1) return 0;
	if (dp[day][count][friend_count] != 0) return dp[day][count][friend_count];

	int adder = 0;
	int cur_people = cur_count[day];
	if (cur_people >= t)
	{
		friend_count = 0;
		return dp[day][count][friend_count] = travel(day + 1, count, friend_count) + 1;
	}

	for (int i = 0; i <= k; i++)
	{
		if (count - i < 0) break;
		if (cur_people + friend_count + i >= t) adder = 1;
		dp[day][count][friend_count] = max(dp[day][count][friend_count], travel(day + 1, count - i, friend_count + i) + adder);
	}

	return dp[day][count][friend_count];
}

int main()
{
	FAST;
	cin >> n >> m >> k >> t;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cur_count[s]++;
		cur_count[e]--;
	}

	for (int i = 1; i <= n + 1; i++)
		cur_count[i] += cur_count[i - 1];

	int ans = travel(1, k, 0);
	cout << ans << "\n";
	return 0;
}