#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

int main() {
	FAST;

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int m; cin >> m;
	vector<int> brr(m);
	for (int i = 0; i < m; i++) {
		cin >> brr[i];
	}

	vector<int> answer;

	int cur_key = 100;
	int left = 0, right = 0;

	while (left < n && right < m && cur_key != 0) {
		int t_left = -1, t_right = -1;

		for (int i = left; i < n; i++) {
			if (arr[i] == cur_key) {
				t_left = i;
				break;
			}
		}

		for (int i = right; i < m; i++) {
			if (brr[i] == cur_key) {
				t_right = i;
				break;
			}
		}

		if (t_left == -1 || t_right == -1) {
			cur_key--;
		}
		else {
			answer.push_back(cur_key);
			left = t_left + 1;
			right = t_right + 1;
		}
	}


	cout << answer.size() << "\n";

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

    return 0;
}