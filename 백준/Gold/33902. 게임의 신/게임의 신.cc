#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	FAST;

	int x, y; cin >> x >> y;
	
	vector<int> dp(1001);

	for (int i = y; i >= x; i--) {
		for (int j = y; j > i; j--) {
			if (gcd(j, i) == 1 && dp[j] == 0)
			{
				dp[i] = 1;
				break;
			}
		}
	}

	if (dp[x] != 1)
	{
		cout << "putdata";
	}
	else {
		cout << "khj20006";
	}

	
	return 0;
}

