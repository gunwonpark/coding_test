#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int l[200001];

int main()
{
	FAST;

	string a, b; cin >> a >> b;
	
	int x = 0, y = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '(')
		{
			x++;
			l[x]++;
		}
		else
		{
			if (x == 0) {
				break;
			}

			x--;
			l[x]++;
		}
	}

	ll answer = 0;

	x = 0; y = 0;

	for (int i = 0; i < b.size(); i++) {
		if (b[i] == ')')
		{
			if (x > 0)
			{
				x--;
			}
			else 
			{
				y++;
			}

			if (x == 0)
			{
				answer += l[y];
			}
		}
		else
		{
			x++;
		}
	}
	
	
	cout << answer;

	return 0;
}

