#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;


int main()
{
	FAST;
	int n, m; cin >> n >> m;

	if (n == 1 && m == 1)
	{
		cout << -1;
	}
	else if(n == 1 && m == 2)
	{
		cout << 3 << '\n';
		cout << 1 << " " << 4;
	}
	else if (n == 2 && m == 1)
	{
		cout << 1 << " " << 6 << '\n';
		cout << 2;
	}
	else if (n == 1 && m > 2)
	{
		cout << m + n << '\n';
		for (int i = 1; i < m; i++)
		{
			cout << i << " ";
		}

		cout << 100000000 << "\n";
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			cout << i << " ";
		}

		cout << 100000000 << "\n";

		for (int i = n; i < n + m; i++)
		{
			cout << i << " ";
		}
	}

	return 0;
}

