#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main()
{
	FAST;

	int n, l, r; cin >> n >> l >> r;
	string s; cin >> s;

	vector<int> pos;
	pos.push_back(-1);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'N' || s[i] == 'C')
		{
			pos.push_back(i);
		}
	}
	pos.push_back(n);
	
	ll answer = 0;

	for(int i = 1; i < pos.size() - 2; i++)
	{
		int left = pos[i];
		int right = pos[i + 1];

		if (s[left] != 'N' || s[right] != 'C')
		{
			continue;
		}

		// 홀수일 경우 불가능
		if ((right + left) % 2 != 0)
		{
			continue;
		}

		int p_pos = (left + right) / 2;

		if (s[p_pos] == 'P')
		{
			int minLength = right - left + 1;
			int enableLeft = left - pos[i - 1] - 1;
			int enableRight = pos[i + 2] - right - 1;

			int maxLength = minLength;
			
			if (r >= minLength && l <= maxLength + enableLeft + enableRight)
			{
				int final_max = min(r, maxLength + enableLeft + enableRight);
				int final_min = max(l, minLength);

				for (int i = final_min; i <= final_max; i++)
				{
					int target = i - minLength;
					int min_value = min(enableLeft, enableRight);
					int max_value = max(enableLeft, enableRight);

					if (target <= max_value)
					{
						answer += (min(min_value, target) + 1);
					}
					else
					{
						answer += (min_value - (target - max_value) + 1);
					}
				}

			}
		}
	}

	cout << answer;

	return 0;
}

