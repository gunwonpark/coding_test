#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;





int main()
{
	FAST;
	int n; cin >> n;
	vector<pair<ll, ll>> arr;

	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		
		if (x >= 0)
		{
			arr.push_back({ i - 1, x });
			continue;
		}
		
		int index = i - 1;
		ll value = x;
		while (index >= 0)
		{
			ll curValue = arr[index].second;
			value += curValue;
			if (value >= 0)
			{
				arr.push_back({ arr[index].first, value});
				break;
			}

			index = arr[index].first;
		}
			
		if (value < 0)
		{
			cout << -1;
			return 0;
		}
	}

	int index = n - 1;
	int answer = 0;
	while (index >= 0)
	{
		answer++;
		index = arr[index].first;
	}

	cout << answer;

	return 0;
}

