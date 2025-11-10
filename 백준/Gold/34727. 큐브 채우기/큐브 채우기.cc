#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;
	
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        if ((n & 1) == 0)
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
		cout << '\n';
    }
    

    return 0;
}
