#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;


ll CalcLanCount(vector<ll>& arr, ll number) {
    ll res = 0;
    for (auto i : arr) {
        res += i / number;
    }
    return res;
}


int main() {
    FAST;

    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll max = arr[n - 1];
    ll mid = arr[n - 1];
    ll min = 1;


    while (true) {
        ll res = CalcLanCount(arr, mid);

        if (res < k) {
            max = mid;
            mid = (max + min) / 2;
        }
        else {
            min = mid;
            mid = (max + min) / 2;
        }

        if (min == mid) {
            cout << mid;
            break;
        }
    }

    return 0;
}