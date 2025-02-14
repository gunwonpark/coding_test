#include <bits/stdc++.h>

#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

int main() {
	FAST;	

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		string s; cin >> s;

		if (n == 1 || n == 3) {
			cout << -1 << '\n';
			continue;
		}

		if (n == 2) {
			if (s[0] == s[1]) cout << 1 << '\n';
			else cout << 0 << '\n';
			continue;
		}

		if((s[0] == '0' && s[1] == '0' && s[n - 2] == '0' && s[n - 1] == '0')
			|| (s[0] == '1' && s[1] == '1' && s[n - 1] == '1' && s[n - 2] == '1')) {
			cout << 2 << '\n';
			continue;
		}

		if ((s[0] == '0' && s[1] == '0' && s[n - 2] == '1' && s[n - 1] == '1')
			|| (s[0] == '1' && s[1] == '1' && s[n - 1] == '0' && s[n - 2] == '0')) {
			int i = 0;
			for (; i < n / 2; i++) {
				if (i != 0 && (s[i] != s[i - 1] || s[n - i - 1] != s[n - i])) break;
			}

			if (i == n / 2) {
				if (n % 2 == 0) cout << 0 << '\n';
				else cout << 2 << '\n';
			}
			else {
				if (s[i] == s[n - i - 1]) cout << 1 << '\n';
				else cout << 0 << '\n';
			}
			continue;
		}

		if ((s[0] == '1' && s[1] == '0' && s[n - 2] == '1' && s[n - 1] == '0')
			|| (s[0] == '0' && s[1] == '1' && s[n - 2] == '0' && s[n - 1] == '1')) {
			cout << 0 << '\n';
			continue;
		}

		if ((s[0] == '0' && s[1] == '1' && s[n - 2] == '1' && s[n - 1] == '0')
			|| (s[0] == '1' && s[1] == '0' && s[n - 2] == '0' && s[n - 1] == '1')) {
			cout << 2 << '\n';
			continue;
		}

		cout << 1 << '\n';
		continue;
	}

	return 0;
}