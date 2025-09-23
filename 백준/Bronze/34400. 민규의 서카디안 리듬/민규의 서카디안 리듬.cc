#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;

    bool save[1001];

    for (int i = 0; i < 1001; i++)
    {
        int value = i % 25;

        if (value < 17) save[i] = true;
        else save[i] = false;
    }


    int q; cin >> q;
    while (q--)
    {
        int t; cin >> t;

        if (save[t]) cout << "ONLINE\n";
		else cout << "OFFLINE\n";
    }


    return 0;
}
