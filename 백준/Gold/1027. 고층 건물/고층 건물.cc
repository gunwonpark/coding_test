#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

int main() {
	FAST;

	int answer = 0;
	int n; cin >> n;
	vector<int> buildings(n);

	for (int i = 0; i < n; i++) {
		cin >> buildings[i];
	}

	for (int i = 0; i < n; i++) {
		int left = i - 1, right = i + 1;

		int temp = 0;

		ll prevDemonitor = 1;
		ll prevNumerator = -(1e9 + 1);
		while (left >= 0) {
			int demonitor = i - left;
			int numerator = buildings[left] - buildings[i];

			if (prevNumerator * demonitor < numerator * prevDemonitor) {
				temp++;
				prevDemonitor = demonitor;
				prevNumerator = numerator;
			}

			left--;
		}

		prevDemonitor = 1;
		prevNumerator = -(1e9 + 1);

		while (right < n) {
			ll demonitor = right - i;
			ll numerator = buildings[right] - buildings[i];
			if (prevNumerator * demonitor < numerator * prevDemonitor) {
				temp++;
				prevDemonitor = demonitor;
				prevNumerator = numerator;
			}
			right++;
		}

		answer = max(answer, temp);
	}

	cout << answer;
	return 0;
}

