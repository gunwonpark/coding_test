#include <bits/stdc++.h>
#include <unordered_set>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

typedef long long ll;

using namespace std;

ll fibo[1001];

int main() {
	FAST;

	int T; cin >> T;

	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= 1000; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]);
	}

	while (T--) {
		ll x, y;
		cin >> x >> y;


		int index = 0;

		for (; index < 1001; index++) {
			if (fibo[index + 1] > y || fibo[index + 2] > x) {
				break;
			}
		}
		cout << fibo[index + 1] << " " << fibo[index] << '\n';
	}

	return 0;
}