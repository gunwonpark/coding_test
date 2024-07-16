#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;

ll n, k;

ll Solution(ll start, ll end) {
    ll mid = (start + end) / 2;
    ll temp = 0;

    

    while (start <= end) {
        for (ll i = 1; i <= n; ++i) {
            temp += min(mid / i, n);
        }

        if (temp < k) {
            start = mid + 1;
        }
        else if (temp >= k) {            
            end = mid - 1;            
        }

        mid = (start + end) / 2;
        temp = 0;
    }

    return start;
    
}


int main() {
    FAST;    
    cin >> n >> k;

    ll res = Solution(1, k);

    cout << res;

    return 0;
}


