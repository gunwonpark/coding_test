#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

int main() {
    FAST;

    int n; cin >> n;
    int sx, sy, ex, ey; cin >> sx >> sy;
	ex = sx, ey = sy;

    for (int i = 1; i < n; i++)
    {
        int x, y; cin >> x >> y;
		sx = min(sx, x);
		sy = min(sy, y);
		ex = max(ex, x);
		ey = max(ey, y);
    }

	cout << (ex - sx) * (ey - sy) << '\n';
    
    return 0;
}