#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<deque>
#include<unordered_set>
#include<unordered_map>
#include<cmath>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

int main() {
	Fast;
	int n;
	cin >> n;

	vector<int> arr(n);
	int left = 0, right = n - 1;
	int left_index = 0, right_index = n - 1;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cur_max = 2000000000;

	while (left_index < right_index) {
		int left_value = arr[left_index];
		int right_value = arr[right_index];

		int diff = abs(left_value + right_value);

		if (diff == 0) {
			cout << left_value << " " << right_value;
			return 0;
		}

		if (diff < cur_max) {
			cur_max = diff;
			left = left_value;
			right = right_value;
		}

		if (abs(left_value) > abs(right_value)) {
			left_index++;
		}
		else {
			right_index--;
		}
	}

	cout << left << " " << right;
	return 0;
	
}