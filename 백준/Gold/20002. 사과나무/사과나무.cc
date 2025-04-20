#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

int getSum(int x1, int y1, int x2, int y2, vector<vector<int>>& preSum) {
	int sum = preSum[x2][y2];
	if (x1 > 0) sum -= preSum[x1 - 1][y2];
	if (y1 > 0) sum -= preSum[x2][y1 - 1];
	if (x1 > 0 && y1 > 0) sum += preSum[x1 - 1][y1 - 1];
	return sum;
}

int main() {
	FAST;

	int n; cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	vector<vector<int>> preSum(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) {
				preSum[i][j] = arr[i][j];
			}
			else if (i == 0) {
				preSum[i][j] = preSum[i][j - 1] + arr[i][j];
			}
			else if (j == 0) {
				preSum[i][j] = preSum[i - 1][j] + arr[i][j];
			}
			else {
				preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + arr[i][j];
			}
		}
	}

	int maxSum = -1000;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				int x1 = i, y1 = j;
				int x2 = i + k, y2 = j + k;

				if (x1 < 0 || y1 < 0 || x2 >= n || y2 >= n) continue;

				int sum = getSum(x1, y1, x2, y2, preSum);
				maxSum = max(maxSum, sum);
			}
		}
	}

	cout << maxSum << endl;
	return 0;
}