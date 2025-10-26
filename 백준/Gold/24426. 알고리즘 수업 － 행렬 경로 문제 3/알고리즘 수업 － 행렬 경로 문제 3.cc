#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;

    int n; cin >> n;

	vector<vector<ll>> board(n + 1, vector<ll>(n + 1, 0));
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
	}

    int a, b; cin >> a >> b;
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            dp[i][j] = board[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        }
	}

    for (int i = a; i <= n; i++) {
        for (int j = b; j <= n; j++) {
            if (i == a && j == b)
            {
                continue;
            }
            dp[i][j] = board[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

	cout << dp[n][n] << " ";

	dp.assign(n + 1, vector<ll>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == a && j == b)
            {
                dp[i][j] = -1;
            }
            else
            {
                if(dp[i - 1][j] == -1 && dp[i][j - 1] == 0)
                    dp[i][j] = -1;
                else if(dp[i - 1][j] == 0 && dp[i][j - 1] == -1)
                    dp[i][j] = -1;
				else
                    dp[i][j] = board[i][j] + max({ dp[i - 1][j], dp[i][j - 1]});
            }
        }
    }

    cout << dp[n][n];

    return 0;
}
