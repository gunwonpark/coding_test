#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;
    int T; cin >> T;
    while (T--)
    {
        int n, m; cin >> n >> m;
        int count = 0;
        for(int i = 0; i < n; i++) {
            string temp; cin >> temp;
            for(int j = 0; j < m; j++) {
                if (temp[j] == '.')
                    count++;
            }
		}

        if (count % 2 == 1)
        {
            cout << "sewon" << '\n';
        }
        else
        {
            cout << "pizza" << '\n';
        }

    }
    

    return 0;
}
