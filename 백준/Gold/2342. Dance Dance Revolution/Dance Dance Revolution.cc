#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

int calc_cost(int st, int to) {
    if (st == 0) return 2;
    if (st == to) return 1;
    if (abs(st - to) == 2) return 4;
    return 3;
}

vector<int> v;
int dp[5][5][100001];

int solve(int y, int x, int target) {
    if (target == v.size()) return 0;
    if (dp[y][x][target] != -1) return dp[y][x][target];

    int left = solve(v[target], x, target + 1) + calc_cost(y, v[target]);
    int right = solve(y, v[target], target + 1) + calc_cost(x, v[target]);

    return dp[y][x][target] = min(left, right);
}

int main() {
    FAST;
    int n;

    memset(dp, -1, sizeof(dp));
    while (cin >> n) {
        if (n == 0) break;
        v.push_back(n);
    }
   
    cout << solve(0, 0, 0);

    return 0;
}