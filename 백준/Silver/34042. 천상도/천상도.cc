#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;





int main()
{
	FAST;
	
	int n, m; cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		ll tempMinus = 0;
		ll minus = 1;
		ll zero = 1;
		ll plus = 1;
		ll zeroCount = 0;
		ll plusCount = 0;
		ll minusCount = 0;
		for (int j = 0; j < m; j++)
		{
			ll x; cin >> x;
			if (x < 0)
			{
				minusCount++;
				minus *= x;
				if (tempMinus == 0)
				{
					tempMinus = x;
				}
				else
				{
					tempMinus = max(tempMinus, x);
				}
			}
			if (x == 0)
			{
				zeroCount++;
				zero *= x;
			}
			if (x > 0)
			{
				plusCount++;
				plus *= x;
			}
		}

		if (m == 1 || zeroCount == m) cout << minus * zero * plus;
		else if (plusCount == 0)
		{
			if (minusCount <= 1)
			{
				cout << 0;
			}
			else
			{
				cout << (minus > 0 ? minus : minus / tempMinus);
			}
		}
		else
		{
			cout << plus * (minus > 0 ? minus : (tempMinus != 0 ? minus / tempMinus : 1));
		}
		cout << '\n';
	}


	return 0;
}

