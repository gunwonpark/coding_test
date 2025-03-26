#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

int n, m;
vector<int> arr;
vector<int> sums;
int dp[301][301];
pair<int ,int> tracer[301][301];

int solve(int curCount, int left_group) {
	if (left_group == 1) {
		dp[curCount][left_group] = sums[n] - sums[n - curCount];
		return dp[curCount][left_group];
	}

	if (dp[curCount][left_group] != 1e9) {
		return dp[curCount][left_group];
	}

	int startIndex = n - curCount;
	for (int i = 1; i <= curCount - left_group + 1; i++) {
		int left_count = curCount - i;
		int cur_sum = sums[startIndex + i] - sums[startIndex];
		int next_sum = solve(left_count, left_group - 1);

		int value = max(cur_sum, next_sum);

		if (dp[curCount][left_group] > value) {
			dp[curCount][left_group] = value;
			tracer[curCount][left_group] = { left_count, left_group - 1 };
		}
	}

	return dp[curCount][left_group];
}

int main() {
	FAST;

	cin >> n >> m;
	arr.resize(n);
	sums.resize(n + 1);
	fill(&dp[0][0], &dp[0][0] + 300 * 300, 1e9);
    fill(&tracer[0][0], &tracer[0][0] + 300 * 300, make_pair(-1, -1));

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sums[0] = 0;
	for (int i = 0; i < n; i++) {
		sums[i + 1] = sums[i] + arr[i];
	}

	cout << solve(n, m) << "\n";
	
	int key = m;
	while (key != 1) {
		cout << n - tracer[n][key].first << " ";
		n = tracer[n][key].first;
		key--;
	}

	cout << n << "\n";
	return 0;
}
