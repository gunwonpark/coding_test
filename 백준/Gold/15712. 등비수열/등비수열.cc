#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

ll mod;
ll result = 0;

ll cal(ll r, ll n)
{
    ll res = 1;
    r %= mod;

    while (n > 0)
    {
        if (n & 1)
        {
            res = res * r % mod;
        }

        r = (r * r) % mod;
        n >>= 1;
    }

    return res;
}

ll S(ll r, ll n)
{
    if (n == 0)
        return 0;

    if (n % 2 == 0)
    {
        ll half = S(r, n / 2);
        return (half + cal(r, n / 2) * half % mod) % mod;
    }
    else
    {
        return (S(r, n - 1) + cal(r, n - 1)) % mod;
    }
}

int main() {
    FAST;

    ll a, r, n;

	cin >> a >> r >> n >> mod;

	result = a * S(r, n) % mod;

	cout << result << "\n";

    return 0;
}
