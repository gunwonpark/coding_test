#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;


int main() {
	FAST;

	int key = 0;
	int n; cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	
	int answer = 0;
	int maxlength = 0;
	for (int i = 0; i < n; i++) {
		key = arr[i];
		int cur = -1;
		maxlength = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] == key) {
				continue;
			}

			if (cur == -1) {
				maxlength = 1;
				cur = arr[j];
			}
			else if (cur != arr[j]) {
				cur = arr[j];
				answer = max(answer, maxlength);
				maxlength = 1;
			}
			else {
				maxlength++;
			}
		}
		answer = max(answer, maxlength);
	}

	cout << answer << endl;
	
	return 0;
}
