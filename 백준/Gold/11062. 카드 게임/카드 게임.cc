#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using ll = long long;

using namespace std;

vector<int> card;

pair<int, int> dfs(vector<vector<pair<int, int>>>& dp, int left, int right) {
    if (dp[left][right].first != -1) {
        return dp[left][right];
    }

    pair<int, int> leftRes = dfs(dp, left + 1, right);
    pair<int, int> rightRes = dfs(dp, left, right - 1);

    if (leftRes.second + card[left] > rightRes.second + card[right]) {
        dp[left][right] = { leftRes.second + card[left], leftRes.first };
    }
    else {
        dp[left][right] = { rightRes.second + card[right], rightRes.first };
    }

    return dp[left][right];
}

int main() {
    Fast;

    int T; cin >> T;
    while(T--){
        int N; cin >> N;

        card.clear();
        card.resize(N);
        
        for (int i = 0; i < N; i++) {
            cin >> card[i];
        }

        if (N == 1) {
            cout << card[0] << '\n';
            continue;
        }

        vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(N, { -1, -1 }));

        for (int i = 0; i < N - 1; i++) {
            dp[i][i + 1].first = max(card[i], card[i + 1]);
            dp[i][i + 1].second = min(card[i], card[i + 1]);
        }

        dfs(dp, 0, N - 1);

        cout << dp[0][N - 1].first << '\n';
    }
   
    return 0;
}