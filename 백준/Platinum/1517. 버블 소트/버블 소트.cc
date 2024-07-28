#define _CRT_SECURE_NO_WARNINGS

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

ll result = 0;
vector<int> temp;
vector<int> arr;

void mergeFind(int start, int end) {

	if (start >= end) return;

	int mid = (start + end) / 2;

	mergeFind(start, mid);
	mergeFind(mid + 1, end);

	for (int i = start; i <= end; ++i) {
		temp[i] = arr[i];
	}

	int index = start;
	int part1 = start;
	int part2 = mid + 1;

	while (part1 <= mid && part2 <= end) {
		if (temp[part1] > temp[part2]) {
			arr[index] = temp[part2];
			
			result += part2 - index;

			index++;
			part2++;
		}
		else {
			arr[index] = temp[part1];

			index++;
			part1++;
		}
	}

	for (int i = part1; i <= mid; ++i) {
		arr[index] = temp[i];
		index++;
	}

	for (int i = part2; i <= end; ++i) {
		arr[index] = temp[i];
		index++;
	}
}

int main() {
	FAST;

	int n;

	cin >> n;

	arr.resize(n);
	temp.resize(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	mergeFind(0, n - 1);

	cout << result;
	return 0;
}


