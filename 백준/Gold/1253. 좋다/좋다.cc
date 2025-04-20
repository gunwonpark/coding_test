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
	
	set<int> s;
	map<int, int> zero_map;
	map<int, int> num_map;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] != 0 && arr[j] != 0) {
				s.insert(arr[i] + arr[j]);
			}
			else {
				if (arr[i] == 0 && arr[j] == 0) {
					continue;
				}
				if (arr[i] == 0) {
					zero_map[arr[j]]++;
				}
				else if(arr[j] == 0){
					zero_map[arr[i]]++;
				}
			}
		}
	}

	int zero_count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			zero_count++;
		}
		else {
			num_map[arr[i]]++;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s.find(arr[i]) != s.end()) {
			ans++;
		}
		else if (zero_map.find(arr[i]) != zero_map.end() && num_map[arr[i]] >= 2) {
			ans++;
		}
		else if (arr[i] == 0 && zero_count >= 3) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}