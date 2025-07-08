#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main()
{
	FAST;

	int n; cin >> n;
	string s; cin >> s;
	string answer = s;

	for (int i = 0; i < n; i++)
	{
		char key = s[i];
		bool find = false;
		for (int j = i + 1; j < n; j++)
		{
			char cur = s[j];

			if (key >= cur)
			{
				continue;
			}

			find = true;
			string temp = s;
			reverse(temp.begin() + i, temp.begin() + j + 1);
			
			if (temp > answer)
			{
				answer = temp;
			}
		}
		if (find)
		{
			break;
		}
	}

	cout << answer;

	return 0;
}

