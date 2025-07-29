#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main()
{
	FAST;
	int T; cin >> T;
	while (T--)
	{
		int n, k; cin >> n >> k;

		vector<int> a;
		if (k != 1)
		{
			for (int i = 1; i <= n; i++)
			{
				cout << i << " ";
			}
		}
		else
		{
			if (n < 4)
			{
				cout << -1;
			}
			else if (n == 4)
			{
				cout << "2 4 1 3";
			}
			else if (n == 5)
			{
				cout << "4 2 5 1 3";
			}
			else
			{
				for (int i = 1; i <= 3; i++)
				{
					a.push_back(i);
				}
				for (int i = 4; i <= n; i++)
				{
					a.push_back(i);
					if (i % 2 == 0)
					{
						swap(a[i - 1], a[i - 4]);
					}
				}
				for (int i = 0; i < n; i++)
				{
					cout << a[i] << " ";
				}
			}
		}
		cout << "\n";
	}

	return 0;
}

