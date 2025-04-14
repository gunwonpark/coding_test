#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;




int main() {
	FAST;

	ll n, k; cin >> n >> k;
	vector<ll> arr;

	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	if (arr.back() > k) {
		cout << 0;
	}
	else if (arr[0] <= 0) {
		cout << -1;
	}
	else {
		ll key = arr[0];
		ll ans = 1;
		for (int i = arr.size() - 1; i >= 1; i--) {
			ll cur = arr[i];
			ll left = k - cur;
			ans += left / key;
		}
		cout << ans;
	}



	return 0;
}