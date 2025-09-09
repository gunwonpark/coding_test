#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int n;
vector<pair<int, int>> board;
int sx, ex, sy, ey;
int main()
{
	FAST;
	
	cin >> n;

	board.resize(n * n + 1);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			board[a] = { i, j };
			if(a == 1)
			{
				sx = i;
				sy = j;
				ex = i;
				ey = j;
			}
		}
	}

	int ans = 1;

	for(int i = 2; i <= n * n; i++)
	{
		int x = board[i].first;
		int y = board[i].second;
		
		sx = min(sx, x);
		sy = min(sy, y);
		ex = max(ex, x);
		ey = max(ey, y);

		if((ex - sx + 1) * (ey - sy + 1) == i)
		{
			ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}