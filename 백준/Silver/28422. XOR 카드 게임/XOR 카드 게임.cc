#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

int dp[100005];
int arr[100005];

int calc_two(int a, int b) {
    int res = a ^ b;
    int count = 0;

    while (res > 0) {
        count += res & 1;
        res >>= 1;
    }

    return count;
}

int calc_three(int a, int b, int c) {
    int res = a ^ b ^ c;
    int count = 0;

    while (res > 0) {
        count += res & 1;
        res >>= 1;
    }

    return count;
}

int main() {
    Fast;

    int n; cin >> n;

    for (int i = 2; i < n + 2; i++) {
        cin >> arr[i];
    }

    for (int i = 3; i < n + 2; i++) {
        if (i == 4) {
            dp[i] = calc_three(arr[i], arr[i - 1], arr[i - 2]) + dp[i - 3];
        }
        else if (i == 5 || i == 3) {
            dp[i] = calc_two(arr[i], arr[i - 1]) + dp[i - 2];
        }
        else {
            dp[i] = max(calc_two(arr[i], arr[i - 1]) + dp[i - 2], calc_three(arr[i], arr[i - 1], arr[i - 2]) + dp[i - 3]);
        }
    }    

    cout << dp[n + 1];
    return 0;
}