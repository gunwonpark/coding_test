#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int counts[21]{};
int arr[21][200001]{};

int main() {
	FAST;

	int n, k; cin >> n >> k;
	

	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		int t = 0;
		while (num != 0)
		{
			if (num & 1)
			{
				counts[t]++;
				arr[t][i] = 1;
			}
			num >>= 1;
			t++;
		}
	}

	int value = 1 << 20;
	int result = 0;
	set<int> indexs;

	for (int i = 20; i >= 0; i--)
	{
		set<int> temp;
		if (counts[i] >= k)
		{
			if (!indexs.empty())
			{
				for (int j = 0; j < n; j++)
				{
					if(arr[i][j] == 1 && indexs.find(j) != indexs.end())
						temp.insert(j);
				}

				if (temp.size() >= k)
				{
					indexs = temp;
					result += value;
				}
			}
			else
			{
				result += value;
				for (int j = 0; j < n; j++)
				{
					if (arr[i][j] == 1)
						temp.insert(j);
				}
				indexs = temp;
			}
		}
		value >>= 1;
	}

	cout << result << '\n';

	return 0;
}
