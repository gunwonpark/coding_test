#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

int main() {
    FAST;
    int n, k;
    cin >> n >> k;
    vector<int> diff(n);
    ll sum = 0;
    int prev;
    cin >> prev;

    for (int i = 0; i < n - 1; i++) {
        int cur;
        cin >> cur;

        diff[i] = cur - prev;
        sum += diff[i];
        prev = cur;
    }

    sort(diff.begin(), diff.end(), greater<int>());

    for (int i = 0; i < k - 1; i++) {
        sum -= diff[i];
    }

    cout << sum;

    return 0;
}