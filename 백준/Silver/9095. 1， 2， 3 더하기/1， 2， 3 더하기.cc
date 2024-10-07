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

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

int dp[11];

int main() {
	Fast;
	int T;
	cin >> T;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	
	return 0;
	
}