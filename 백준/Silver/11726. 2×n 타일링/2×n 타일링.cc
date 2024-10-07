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

int main() {
	Fast;
	int n;

	cin >> n;

	int dp[1001] = { 0, };
	
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	
	cout << dp[n] << "\n";

	return 0;
	
}