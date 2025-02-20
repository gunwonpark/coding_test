#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

bool check(string a) {
	if (a[0] == '1') return true;
	if (a[0] == '2' && a[1] <= '6') return true;
	return false;
}


int main() {
    FAST;

    string s; cin >> s;

    int n = s.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

	dp[n][0] = 1;
	if (s.back() != '0') dp[n - 1][0] = 1;

    for(int i = 2; i <= n; i++){
        if (s[n - i] != '0') {
			dp[n - i][0] = dp[n - i + 1][0] + dp[n - i + 1][1];

        }
        else {
            dp[n - i][0] = 0;
        }

        // 가능한 조합일 경우
        if (check(s.substr(n - i, 2))) {
			dp[n - i][1] = dp[n - i + 2][0] + dp[n - i + 2][1];
        }
        else {
			dp[n - i][1] = 0;
        }

		dp[n - i][0] %= 1000000;
		dp[n - i][1] %= 1000000;
    }

	cout << (dp[0][0] + dp[0][1]) % 1000000 << '\n';
    return 0;
}