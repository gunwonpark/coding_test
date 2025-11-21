#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

string temp = "";
string result = "";
int dp[51][51]{};
int n;
vector<int> arr;

void travel(int depth, int remain, string& cur)
{
	if (dp[depth][remain]) return;
	dp[depth][remain] = 1;

	if (result.length() < cur.length() || result < cur)
	{
		result = cur;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] <= remain)
		{
			cur += '0' + i;
			travel(depth + 1, remain - arr[i], cur);
			cur.pop_back();
		}
	}
}

int main() {
	FAST;
	cin >> n;
	arr.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int m; cin >> m;

	for (int i = n - 1; i >= 1; i--)
	{
		if (arr[i] <= m)
		{
			temp += '0' + i;
			travel(1, m - arr[i], temp);
			temp.pop_back();
		}
	}

	if(result == "")
	{
		cout << 0;
	}
	else
	{
		cout << result;
	}

	return 0;
}
