#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;



int main()
{
	FAST;

	int n, k; cin >> n >> k;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int minValue = arr[0];
	int maxValue = arr[0] + k;
	
	int answer = minValue;

	while (minValue <= maxValue)
	{
		int midValue = (minValue + maxValue) / 2;

		ll count = 0;

		for (int i = 0; i < n; i++) {
			ll diff = midValue - arr[i];

			if (diff > 0)
			{
				count += diff;
			}
		}

		if(count <= k)
		{
			minValue = midValue + 1;
			answer = max(answer, midValue);
		}
		else
		{
			maxValue = midValue - 1;
		}
	}

	cout << answer;
	return 0;
}

