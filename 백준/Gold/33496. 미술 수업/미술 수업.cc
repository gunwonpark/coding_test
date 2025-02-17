#include <bits/stdc++.h>
#include <unordered_set>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

typedef long long ll;

using namespace std;


int main() {
	FAST;

	int n; cin >> n;
	vector<int> left, right;
	unordered_set<int> left_set, right_set;

	ll answer = 0;

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;

		int left_value = x - y;
		int right_value = x + y;

		auto left_it = left_set.find(left_value);
		auto right_it = right_set.find(right_value);

		if (left_it == left_set.end()) {
			left_set.insert(left_value);
			left.push_back(left_value);
		}
		if (right_it == right_set.end()) {
			right_set.insert(right_value);
			right.push_back(right_value);
		}

	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	unordered_set<int> total;

	for (auto& l : left_set) {
		total.insert(l);
	}

	for (auto& r : right_set) {
		total.insert(r);
	}

	for (int i = 0; i < left.size(); i++) {
		auto index = upper_bound(right.begin(), right.end(), left[i]) - right.begin();

		answer += right.size() - index;
	}

	cout << answer + total.size();



	return 0;
}