#include <bits/stdc++.h>
#include <unordered_set>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

typedef long long ll;

using namespace std;



int main() {
	FAST;

	int T; cin >> T;

	while (T--) {
		ll n; cin >> n;
		
		if (n & 1) {
			cout << n * 2 - 1 << '\n';
		}
		else {
			cout << n * 2 << '\n';
		}
	}

	return 0;
}