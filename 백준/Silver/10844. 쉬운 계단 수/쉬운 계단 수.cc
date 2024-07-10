#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

vector<int> arr;

ll factorial(int n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    

	int n;

	cin >> n;

	vector<int> dp(10, 1);
	vector<int> dp2(10, 0);
	dp[0] = 0;


	int res = 0;

	for (int i = 0; i < n - 1; i++)
	{
		copy(dp.begin(), dp.end(), dp2.begin());
		for (size_t j = 0; j < dp.size(); j++)
		{
			if (j == 0)
				dp[j] = dp2[j + 1];
			else if (j == 9)
				dp[j] = dp2[j - 1];
			else
				dp[j] = (dp2[j - 1] + dp2[j + 1]) % 1000000000;
		}
	}

	

	for (size_t i = 0; i < dp.size(); i++)
	{
		res += dp[i];
		res %= 1000000000;
	}

	cout << res;

	return 0;
}




