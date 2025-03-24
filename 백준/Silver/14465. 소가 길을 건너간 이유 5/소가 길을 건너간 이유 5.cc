#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;


int main() {
	FAST;

	int n, k, b; cin >> n >> k >> b;
	vector<int> broken(n + 1, 0);
	for (int i = 0; i < b; i++) {
		int num; cin >> num;
		broken[num] = -1;
	}

	int ans = 0;
	int l = 1, r = k + 1;
	int answer = 100001;

	for (int i = 1; i < r; i++) {
		if (broken[i] == -1) ans++;
	}

	answer = min(answer, ans);

	while (r <= n) {
		if (broken[l] == -1) ans--;
		if (broken[r] == -1) ans++;
		
		answer = min(answer, ans);

		l++;
		r++;
	}

	ans = 0;
	for (int i = l; i < r; i++) {
		if (broken[i] == -1) ans++;
	}
	answer = min(answer, ans);

	cout << answer << '\n';
	return 0;
}
