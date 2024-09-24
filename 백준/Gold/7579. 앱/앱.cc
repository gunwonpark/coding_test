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

int n, minM;
ll dp[101][10001];

int main() {
	Fast;

	cin >> n >> minM;

	int M[101] = { 0, };
	int C[101] = { 0, };

	for (int i = 1; i <= n; i++) {
		cin >> M[i];
	}

	int maxC = 0;

	for (int i = 1; i <= n; i++) {
		cin >> C[i];
		maxC += C[i];
	}

	int result = 10001;

	for (int i = 1; i <= n; i++) {
		for (int c = 0; c <= maxC; c++) {
			int m = M[i];
			int cost = C[i];

			if (cost > c) {
				dp[i][c] = dp[i - 1][c];
			}
			else {
				dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - cost] + m);
			}

			if(dp[i][c] >= minM)
				result = min(result, c);
		}
	}

	cout << result;

	return 0;
}

