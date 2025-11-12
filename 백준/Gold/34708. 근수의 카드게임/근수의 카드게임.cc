#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
	FAST;

	int n, k; cin >> n >> k;
	if (2 * n > k) cout << -1;
	else if (2 * n == k) cout << k - 1;
	else cout << 2 * n;

	return 0;
}
