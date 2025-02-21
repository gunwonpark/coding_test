#include <bits/stdc++.h>
#include <unordered_map>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

int dp[501][501]{};
int sum[501]{};

int dfs(int s, int e) {
    if (s == e) {
        return 0;
    }

    if (dp[s][e] != 0) {
		return dp[s][e];
    }

    int result = 1e9;

    for (int i = 0; i < e - s; i++) {
		result = min(result, dfs(s, s + i) + dfs(s + i + 1, e) + sum[e + 1] - sum[s]);
    }

	return dp[s][e] = result;
}

int main() {
    FAST;
   
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));

        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + arr[i];
        }
		
        for (int i = 0; i < n - 1; i++) {
			dp[i][i + 1] = arr[i] + arr[i + 1];
        }

        dfs(0, n - 1);

		cout << dp[0][n - 1] << '\n';
    }
    
    return 0;
}