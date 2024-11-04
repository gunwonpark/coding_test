#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

//일반 작대기일 경우와 작대기가 아닐경우 구함
ll dp[2001];

int main() {
    Fast;
    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 3;
    
    for (int i = 3; i <= 2000; i++) {
        dp[i] = dp[i - 2] * 2 + dp[i - 1];
        dp[i] %= 10007;
    }

    cout << dp[N];
    
    return 0;
}