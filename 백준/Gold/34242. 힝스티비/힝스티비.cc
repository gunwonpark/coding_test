#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int main()
{
	FAST;

	string s;
	cin >> s;

	int answer = 0;
	bool hasMinus = false;
	bool twoMinus = false;
	bool oneMinus = false;
	bool makePlus = false;

	for(int i = 0; i < (int)s.length() - 2; i++)
	{
		char c1 = s[i];
		char c2 = s[i + 1];
		char c3 = s[i + 2];

		if (c1 == '-')
		{
			if (c2 == '^' && c3 == '-')
			{
				answer--;
				hasMinus = true;
				i++;
			}
		}
		else if (c1 == '+')
		{
			if(c2 == '^' && c3 == '+')
			{
				answer++;
				i++;
			}
		}
	}

	for (int i = 0; i < (int)s.length() - 4; i++)
	{
		char c1 = s[i];
		char c2 = s[i + 1];
		char c3 = s[i + 2];
		char c4 = s[i + 3];
		char c5 = s[i + 4];

		if (c1 == '-' && c2 == '^' && c3 == '-' && c4 == '^' && c5 == '-')
		{
			twoMinus = true;
			break;
		}
	}

	for (int i = 0; i < (int)s.length() - 3; i++)
	{
		char c1 = s[i];
		char c2 = s[i + 1];
		char c3 = s[i + 2];
		char c4 = s[i + 3];

		if (c1 == '+' && c2 == '^' && c3 == '-' && c4 == '+')
		{
			oneMinus = true;
			break;
		}
		else if(c1 == '+' && c2 == '-' && c3 == '^' && c4 == '+')
		{
			oneMinus = true;
			break;
		}
		else if(c1 == '+' && c2 == '^' && c3 == '^' && c4 == '+')
		{
			makePlus = true;
			break;
		}
	}

	if (twoMinus)
	{
		answer += 2;
	}
	else if (oneMinus || hasMinus || makePlus)
	{
		answer++;
	}

	cout << answer;

	return 0;
}