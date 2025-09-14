#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

string s;

vector<int> segtree;
vector<int> base;

int getScore(char a, char b, char c)
{
	if (a == '+' && b == '^' && c == '+')
		return 1;
	else if (a == '-' && b == '^' && c == '-')
		return -1;
	else
		return 0;
}

int findEnable(int key, int mi, int ma)
{
	int res = 0;
	
	if (key - 2 >= mi) res -= getScore(s[key - 2], s[key - 1], s[key]);
	if (key - 1 >= mi && key + 1 <= ma) res -= getScore(s[key - 1], s[key], s[key + 1]);
	if (key + 2 <= ma) res -= getScore(s[key], s[key + 1], s[key + 2]);

	if (key - 2 >= mi && key + 1 <= ma) res += getScore(s[key - 2], s[key - 1], s[key + 1]);
	if (key - 1 >= mi && key + 2 <= ma) res += getScore(s[key - 1], s[key + 1], s[key + 2]);

	return res;
}

int getPreSum(int left, int right)
{
    if(right - left + 1 < 3) return 0;
	return base[right - 1] - base[left];
}

int init(int left, int right, int index)
{
	int leftIndex = index * 2 + 1;
	int rightIndex = index * 2 + 2;

	int mid = (left + right) / 2;

	if (left == right)
	{
		int key = left;

		return segtree[index] = findEnable(key, 0, s.size() - 1);
	}

	return segtree[index] = max(init(left, mid, leftIndex), init(mid + 1, right, rightIndex));
}

int query(int left, int right, int index, int queryLeft, int queryRight)
{
	if (queryLeft > right || queryRight < left)
		return 0;
	if (queryLeft <= left && queryRight >= right)
		return segtree[index];
	int mid = (left + right) / 2;
	int leftIndex = index * 2 + 1;
	int rightIndex = index * 2 + 2;
	return max(query(left, mid, leftIndex, queryLeft, queryRight), query(mid + 1, right, rightIndex, queryLeft, queryRight));
}

int main()
{
	FAST;

	cin >> s;
	segtree.resize(4 * s.size());
	base.resize(s.size());
	
	for (int i = 1; i < s.size() - 1; i++)
	{
		char c1 = s[i - 1];
		char c2 = s[i];
		char c3 = s[i + 1];

		base[i] = base[i - 1] + getScore(c1, c2, c3);
	}

	base[s.size() - 1] = base[s.size() - 2];

	init(0, s.size() - 1, 0);

	int q; cin >> q;
	while(q--)
	{
		int l, r; cin >> l >> r;
		l--; r--;
		int preSum = getPreSum(l, r);
		int enable = 0;
		if (r - l + 1 >= 5)
		{
			enable = query(0, s.size() - 1, 0, l + 2, r - 2);
			enable = max(enable, findEnable(l, l, r));
			enable = max(enable, findEnable(r, l, r));
			enable = max(enable, findEnable(l + 1, l, r));
			enable = max(enable, findEnable(r - 1, l, r));
		}
		else
		{
			for (int i = l; i <= r; i++)
			{
				enable = max(enable, findEnable(i, l, r));
			}
		}

		if (enable < 0) enable = 0;

		cout << preSum + enable << '\n';
	}

	return 0;
}