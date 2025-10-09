#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;

    int n; cin >> n;
    vector<int> a(n);

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    int full = 2 * total + 1;
    vector<int> dp(full, -1);
    dp[total] = 0;

    for (int i = 0; i < n; i++)
    {
        int value = a[i];
        vector<int> old_dp = dp;
        for (int j = 0; j < full; j++)
        {
			if (old_dp[j] == -1) continue;
            if (j + value < full)
            {
				dp[j + value] = max(dp[j + value], old_dp[j] + value);
            }

            if (j - value >= 0)
            {
				dp[j - value] = max(dp[j - value], old_dp[j]);
            }
        }
    }

	cout << (dp[total] == 0 ? -1 : dp[total]) << "\n";


    return 0;
}
