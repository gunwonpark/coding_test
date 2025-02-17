#include <bits/stdc++.h>

#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

typedef long long ll;

using namespace std;


int main() {
	FAST;	
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;

		cout << "YES\n";
		for (int i = 1; i <= n; i++) {
			cout << i << " ";
		}
		cout << '\n';
	}

	return 0;
}