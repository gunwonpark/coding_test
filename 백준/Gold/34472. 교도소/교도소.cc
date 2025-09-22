#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;

    int n; cin >> n;

    ll total = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    ll ans = 0;
    ll avg = total / n;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > avg)
        {
            ll remove = arr[i] - avg;
            ans += remove;
			arr[i] -= remove;
            int next = (i + 1) % n;
            arr[next] += remove;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > avg)
        {
            ll remove = arr[i] - avg;
            arr[i] -= remove;
            ans += remove;
            int next = (i + 1) % n;
            arr[next] += remove;
        }
    }

    cout << ans;    


    return 0;
}
