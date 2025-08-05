#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
typedef long long ll;

using namespace std;


int main()
{
	FAST;
	int n, k; cin >> n >> k;

	vector<int> a;
	vector<pair<int, int>> b;
	a.resize(n + 1);
	b.resize(n);

	for (int i = 0; i < n; i++)
	{
		int input; cin >> input;
		a[input] = i;
	}

	for (int i = 0; i < n; i++)
	{
		int input; cin >> input;
		int index = a[input];
		b[i].first = input; // 실제 값
		b[i].second = index; // 정렬용 인덱스 값
	}

	vector<pair<int, int>> arr;
	vector<pair<int, int>> ans;
	arr.push_back(b[n-1]);
	for (int i = n - 2; i >= 0; i--)
	{
		int value = b[i].first;
		int index = b[i].second;
		int pos = lower_bound(arr.begin(), arr.end(), make_pair(value, index), [](const pair<int, int>& a, const pair<int, int>& b) {
			return a.second < b.second;			
			}) - arr.begin();

		arr.push_back(b[i]);
		for (int j = arr.size() - 1; j > pos; j--)
		{
			ans.push_back(make_pair(value, arr[j - 1].first));
			if (ans.size() == k)
			{
				std::cout << "Yes\n";
				for(const auto& p : ans)
				{
					std::cout << p.first << " " << p.second << "\n";
				}
				return 0;
			}
			swap(arr[j], arr[j - 1]);
		}
	}

	std::cout << "No\n";

	return 0;
}

