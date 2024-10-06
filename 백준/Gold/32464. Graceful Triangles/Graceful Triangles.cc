#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

ll n;
ll up_dp[100002] = { 0, };
ll down_dp[100002] = { 0, };

int main() {
	Fast;
	cin >> n;

	ll edge_count = 2 * n + 1;
	ll node_count = n + 2;

	ll up_index = 1;
	ll down_index = 1;

	if (n % 2 == 0) {
		up_dp[0] = n + n / 2 + 2;
	}
	else {
		up_dp[0] = n + (n + 1) / 2 + 1;
	}

	down_dp[0] = 1;

	for (int i = 2; i < node_count; i++) {
		if (i % 2 == 0) {
			//up_turn
			up_dp[up_index] = up_dp[up_index - 1] + 2 * up_index - 1;
			up_index++;
		}
		else {
			//down_turn
			down_dp[down_index] = down_dp[down_index - 1] + 2 * down_index;
			down_index++;
		}
	}

	for (int i = 0; i < node_count; i++) {
		if (i % 2 == 0)
			cout << up_dp[i / 2] << " ";
		else
			cout << down_dp[i / 2] << " ";
	}


	return 0;

}