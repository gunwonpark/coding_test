#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>
#include <string>
#include <map>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;


vector<int> arr_a;
vector<int> arr_b;

void SliceSort(int start, int end) {
	vector<int> temp;
	for (int i = start; i <= end; ++i) {
		temp.push_back(arr_a[i]);
	}

	sort(temp.begin(), temp.end());

	int idx = 0;
	for (int i = start; i <= end; ++i) {
		arr_a[i] = temp[idx++];
	}
}

int main() {
	FAST;

	int n;
	cin >> n;

	int input;

	for (int i = 0; i < n; ++i) {
		cin >> input;
		arr_a.push_back(input);
	}

	for (int i = 0; i < n; ++i) {
		cin >> input;
		arr_b.push_back(input);
	}

	arr_a.push_back(-1);
	arr_b.push_back(-1);

	int end = 0;
	int res = true;

	for (int i = arr_b.size() - 1; i >= 0; --i) {
		if (arr_b[i] != arr_a[i]) {
			SliceSort(0, i);
			end = i;
			res = false;
			break;
		}
	}

	int result = 1;

	if (res == false) {		
		bool chance_a = true;
		bool chance_b = true;
		int chance_idx_a = 0;
		int chance_idx_b = 0;

		for (int i = 0; i <= end; ++i) {
			if (arr_a[i + chance_idx_a] != arr_b[i + chance_idx_b]) {
				if (chance_a) {
					chance_a = false;
					chance_idx_a = 1;
					i--;
				}
				else {
					result = 0;
					break;
				}
			}

			if (arr_b[i] == arr_b[i + 1]) {
				if (chance_b && (chance_a == false)) {
					chance_b = false;
					chance_idx_b = 1;
				}
			}
		}

		if (arr_a[end] != arr_b[end]) {
			result = 0;
		}

		
	}
cout << result;
	return 0;
}


