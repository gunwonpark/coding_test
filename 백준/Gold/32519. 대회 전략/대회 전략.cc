#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

struct Node {
    int P, T;
    Node() { P = 0; T = 0; };
    Node(int P, int T) : P(P), T(T) {}
};

typedef long long ll;

int main() {
    FAST;

    int n, T;
    cin >> n >> T;
    vector<vector<Node>> dp(4, vector<Node>(n + 1));

    for (int j = 1; j <= 3; j++) {
        for (int i = 1; i <= n; i++) {
            int input;
            cin >> input;
            
            dp[j][i].P = dp[j][i - 1].P + input;
        }
    }
    
    for (int j = 1; j <= 3; j++) {
        for (int i = 1; i <= n; i++) {
            int input;
            cin >> input;

            dp[j][i].T = dp[j][i - 1].T + input;
        }
    }

    for (int j = 1; j <= n; j++) {
        dp[3][j].P = max(dp[3][j].P, dp[3][j - 1].P);
    }

    int result = 0;

    for (int i = 0; i <= n; i++) {
        int check_point = -1;
        for (int j = n; j >= 0; j--) {
            while ((check_point < n) && ((dp[1][i].T + dp[2][j].T + dp[3][check_point + 1].T) <= T)) check_point++;
            if ((dp[1][i].T + dp[2][j].T + dp[3][check_point].T) <= T) result = max(result, dp[1][i].P + dp[2][j].P + dp[3][check_point].P);
        }
    }

    cout << result;
    return 0;
}