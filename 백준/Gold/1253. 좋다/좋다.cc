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
	
	sort(arr.begin(), arr.end());

	map<int, int> num_map;

	for (int i = 0; i < n; i++) {
		num_map[arr[i]]++;
	}

	int ans = 0;
	
	int left{}, right = arr.size() - 1;
	int zero_count = num_map[0];

	for(int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];

			if (arr[i] == 0 || arr[j] == 0) {
				if (sum != 0 && num_map.find(sum) != num_map.end() && num_map[sum] > 1 ) {
					ans += num_map[sum];
					num_map.erase(sum);
				}
				else if (sum == 0 && num_map.find(0) != num_map.end() && num_map[0] > 2) {
					ans += num_map[0];
					num_map.erase(0);
				}
			}
			else {
				if (num_map.find(sum) != num_map.end() && num_map[sum] > 0) {
					ans += num_map[sum];
					num_map.erase(sum);
				}
			}
		}
	}

	cout << ans;

	return 0;
}