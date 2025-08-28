#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll mod = 1e9 + 7;
ll n, k;

ll nCk(ll n, ll k)
{
	if (k > n) return 0;
	if (k == 0 || k == n) return 1;
	k = min(k, n - k); 
	ll numerator = 1; 
	ll denominator = 1;
	for (int i = 0; i < k; i++) {
		numerator = (numerator * (n - i)) % mod;
		denominator = (denominator * (i + 1)) % mod;
	}

	ll denominator_inv = 1, base = denominator, exponent = mod - 2;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			denominator_inv = (denominator_inv * base) % mod;
		}
		base = (base * base) % mod;
		exponent /= 2;
	}
	return (numerator * denominator_inv) % mod;
}

int main()
{
	FAST;
	cin >> k >> n;

	cout << nCk(n + k, k + 1) << "\n";

	return 0;
}