#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main()
{
	FAST;

	int n; cin >> n;
	int k; cin >> k;
	string s; cin >> s;

	int answer = n;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] != s[j]) continue;
			if (s[i] == 'X') continue;
			int adder = j - i + 1;
			answer = min(answer, n - adder);
			for (int k = j + 1; k < n; k++)
			{
				for (int l = k + 1; l < n; l++)
				{
					if (s[k] != s[l]) continue;
					if (s[k] == 'X') continue;

					int adder2 = l - k + 1;
					answer = min(answer, n - (adder + adder2));
				}
			}
		}
	}

	cout << answer;
	

	return 0;
}

