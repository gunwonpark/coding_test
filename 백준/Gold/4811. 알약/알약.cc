#include<bits/stdc++.h>

//c++17 version

using namespace std;
#define FA ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FA;

	int n;
	while (cin >> n && n != 0)
	{
		ll dp[31][31];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if(i - 1 >= 0 && j + 1 <= n) dp[i][j] += dp[i - 1][j + 1];
				if (j > 0) dp[i][j] += dp[i][j - 1];
			}
		}
			
		cout << dp[n][0] << '\n';
	}

    return 0;
}