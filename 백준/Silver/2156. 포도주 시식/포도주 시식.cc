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


int n;
vector<int> arr;
vector<int> dp;


int main() {
	FAST; 	

	cin >> n;

	arr.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	if (n == 1) {
		cout << arr[0] << "\n";
		return 0;
	}
	else if (n == 2) {
		cout << arr[0] + arr[1] << "\n";
		return 0;
	}
	else if (n == 3) {
		int result = max(arr[0] + arr[1], arr[0] + arr[2]);
		result = max(result, arr[1] + arr[2]);
		cout << result << "\n";
	}
	else {
		vector<int> dp(n, 0);
		dp[0] = arr[0];
		dp[1] = arr[0] + arr[1];
		dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
		dp[2] = max(dp[2], dp[1]);
		

		for (int i = 3; i < n; i++) {
			dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
			dp[i] = max(dp[i], dp[i - 1]);
		}

		cout << dp[n - 1] << "\n";
	}
	return 0;
}


