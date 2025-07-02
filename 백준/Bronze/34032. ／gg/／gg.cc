#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;



int main()
{
	FAST;
	int n; string s; cin >> n >> s;

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'O')
		{
			count++;
		}
	}

	if(count >= (n- count))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	
	return 0;
}

