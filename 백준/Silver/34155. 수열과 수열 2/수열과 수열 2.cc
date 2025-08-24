#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int main()
{
	FAST;
	ll n; cin >> n;
	ll answer = 1;
	for(int i = 1; i <= n; i++)
	{
		int input; cin >> input;

		if (input != i)
		{
			answer *= (n - 2);
		}
		else
		{
			answer *= (n - 1);
		}
        
        answer %= 998244353;
	}

	
    cout << answer << "\n";

	return 0;
}