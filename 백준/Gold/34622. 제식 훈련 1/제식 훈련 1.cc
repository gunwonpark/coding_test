#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

// 양 양 일때는 확장 확장 축소
// 양 음 일때에는 

int main() {
    FAST;

    int n, m, d, e, x, y; cin >> n >> m >> d >> e >> x >> y;

    cout << 3 << '\n';
    if (x >= 0 && y >= 0)
    {
        if (y > x)
        {
            cout << 1 << " " << 1 << " " << y + e << '\n';
			cout << 2 << " " << 2 << " " << y + e - x << '\n';
			cout << 1 << " " << 2 << " " << e << '\n';
        }
        else
        {
            cout << 1 << " " << 1 << " " << x + e << '\n';
            cout << 2 << " " << 2 << " " << x + e - y << '\n';
            cout << 2 << " " << 1 << " " << e << '\n';
        }
    }
    else if(x >= 0 && y <= 0)
    {
		cout << 1 << " " << 2 << " " << d - y << '\n';
		cout << 1 << " " << 1 << " " << x + e << '\n';
		cout << 2 << " " << 1 << " " << e << '\n';
    }
    else if (x <= 0 && y >= 0)
    {
		cout << 2 << " " << 1 << " " << d - x << '\n';
		cout << 1 << " " << 1 << " " << y + e << '\n';
		cout << 1 << " " << 2 << " " << e << '\n';
    }
    else
    {
        cout << 1 << " " << 2 << " " << -y + d << '\n';
		cout << 2 << " " << 1 << " " << -x + d - y << '\n';
		cout << 1 << " " << 1 << " " << e << '\n';
	}

    return 0;
}
