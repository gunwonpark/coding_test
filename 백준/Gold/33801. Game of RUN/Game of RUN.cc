#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main()
{
	FAST;
	int T; cin >> T;
	vector<vector<ll>> dp(1000001, vector<ll>(3, 0));
	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[1][2] = 0;

	dp[2][0] = 3;
	dp[2][1] = 1;
	dp[2][2] = 1;

	ll tmpSum = 0;

	for (int i = 3; i <= 1000000; i++) {
		tmpSum += (dp[i - 2][1] + dp[i - 2][2]) % 1000000007;
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + 2 + tmpSum) % 1000000007;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000007;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % 1000000007;
	}

	while (T--) {
		int n; cin >> n;
		cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 1000000007 << '\n';
	}



	return 0;
}

