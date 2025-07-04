#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}

	return a;
}

ll extendedGCD(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll g = extendedGCD(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

int main()
{
	FAST;

	int n; cin >> n;
	vector<pair<ll, ll>> arr(n);

	ll maxDist = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		maxDist = max(maxDist, arr[i].first);
	}
	
	ll cur = arr[0].first;
	ll curDist = arr[0].second;

	for (int i = 1; i < n; i++) {
		ll next = arr[i].first;
		ll nextDist = arr[i].second;

		ll x, y;
		ll g = extendedGCD(curDist, nextDist, x, y);

		if ((next - cur) % g != 0) {
			cout << -1;
			return 0;
		}

		ll m = nextDist / g;
		ll k = x * ((next - cur) / g);

		k = (k % m + m) % m; 

		ll newCur = cur + k * curDist;
		ll newDist = (curDist / g) * nextDist;
		
		cur = newCur % newDist;
		curDist = newDist;
	}

	if (cur < maxDist) {
		ll offset = maxDist - cur;
		ll steps = (offset + curDist - 1) / curDist;
		cur += steps * curDist;
	}

	cout << cur;


	return 0;
}

