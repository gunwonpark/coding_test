#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
	FAST;

	string u_s1 = "114";
	string d_s1 = "144";
	string u_s2 = "322";
	string d_s2 = "332";
	
	int q; cin >> q;
	while (q--)
	{
		int r, c; cin >> r >> c;
		ll k; cin >> k;

		ll enable = c / 3;

		string u_res = "";
		string d_res = "";

		if (r == 1 || c % 3 != 0)
		{
			cout << -1 << '\n';
			continue;
		}

		k -= 1;

		if (k == 0)
		{
			u_res += '0';
			d_res += '0';
		}

		while (k != 0)
		{
			if ((k & 1) == 1)
			{
				u_res += '1';
				d_res += '1';
			}
			else
			{
				u_res += '0';
				d_res += '0';
			}

			k >>= 1;
		}

		if (u_res.length() > enable)
		{
			cout << -1 << '\n';
			continue;
		}

		if(u_res.length() < enable)
		{
			int diff = enable - u_res.length();
			for (int i = 0; i < diff; i++)
			{
				u_res += '0';
				d_res += '0';
			}
		}

		reverse(u_res.begin(), u_res.end());
		reverse(d_res.begin(), d_res.end());

		for (int i = 0; i < u_res.length(); i++)
		{
			if (u_res[i] == '0')
			{
				cout << u_s1;

			}
			else
			{
				cout << u_s2;
			}
		}

		cout << '\n';

		for(int i = 0; i < d_res.length(); i++)
		{
			if (d_res[i] == '0')
			{
				cout << d_s1;
			}
			else
			{
				cout << d_s2;
			}
		}

		cout << '\n';
	}

	return 0;
}
