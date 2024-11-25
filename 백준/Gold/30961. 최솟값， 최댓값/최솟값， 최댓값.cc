#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using ll = long long;

using namespace std;


int main() {
    Fast;
    int n; cin >> n;
    vector<ll> arr(n);

    ll result = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        result ^= (arr[i] * arr[i]);
    }

    sort(arr.begin(), arr.end());

    ll cur = 0;
    ll prev = 0;
    for (int i = 0; i < n; i++) {
        cur = arr[i];
        result ^= (cur * prev);
        prev = cur;
    }

    cout << result;
    return 0;
}