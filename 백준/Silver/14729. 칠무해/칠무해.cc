#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;




int main() {
	FAST;
	int n; cin >> n;
	vector<float> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	cout.precision(3);
	cout << fixed;
	for (int i = 0; i < 7; i++) {
		cout << arr[i] << '\n';
	}

    return 0;
}