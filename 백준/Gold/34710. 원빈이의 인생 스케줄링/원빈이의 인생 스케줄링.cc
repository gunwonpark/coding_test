#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
	FAST;

	int n; cin >> n;
	vector<tuple<int, int, int>> arr(n);

	for (int i = 0; i < n; i++)
	{
		int t, l; cin >> t >> l;
		if (t < l)
		{
			cout << -1;
			return 0;
		}

		arr[i] = make_tuple(t, l, t - l);
	}

	sort(arr.begin(), arr.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
		return get<0>(a) < get<0>(b);
		});

	for (int i = 1; i < n; i++)
	{
		int prev_l = get<1>(arr[i - 1]);
		int curr_t = get<0>(arr[i]);
		int curr_l = get<1>(arr[i]);
		int curr_happy = get<2>(arr[i]);
		if (curr_t - prev_l < curr_happy)
		{
			arr[i] = make_tuple(curr_t, prev_l, curr_t - prev_l);
		}
	}

	int min_happy = get<2>(arr[n - 1]);
	ll cur = min_happy;
	for(int i = n - 2; i >= 0; i--)
	{
		int curr_happy = get<2>(arr[i]);

		if (curr_happy < min_happy)
		{
			min_happy = curr_happy;
		}

		cur += min_happy;
	}

	cout << cur;

	return 0;
}
