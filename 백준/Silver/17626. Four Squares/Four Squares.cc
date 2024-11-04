#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

int main() {
	Fast;

	int n;
	cin >> n;

	int dp[50001];

	memset(dp, 5, sizeof(dp));

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i < 50001; i++) {
		int sq = sqrt(i);
		if (sq * sq == i) dp[i] = 1;
		else {
			for (int j = i - 1; j > (i - 1) / 2; j--) {
				dp[i] = min(dp[i], dp[j] + dp[i - j]);
			}
		}
	}

	cout << dp[n];

	return 0;

}