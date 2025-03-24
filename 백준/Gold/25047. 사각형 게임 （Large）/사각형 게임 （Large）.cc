#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

vector<vector<ll>> arr;
ll n;
ll answer = -(1e18);

void combination() {
	ll count = ((ll)1 << n);
	for (ll i = 0; i < count; i++) {

		

		ll sum = 0;
		for (ll j = 0; j < n; j++) {
			ll cur = i;
			ll checked = 0;
			ll nonchecked = 0;
			for (ll iter = 0; iter < n; iter++) {
				if ((cur & 1) == 1) {
					checked += arr[iter][j];
				}
				else {
					nonchecked += arr[iter][j];
				}
				cur >>= 1;
			}
			sum += min(checked, nonchecked);
		}
		answer = max(answer, sum);
	}
}

int main() {
	FAST;

	cin >> n;

	arr.resize(n, vector<ll>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	combination();

	cout << answer << "\n";
		
	return 0;
}
