#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;

    int n; cin >> n;
    if (n == 3)
    {
        cout << "2 5 29";
    }
    else if (n == 4)
    {
        cout << "2 2 3 17";
    }
    else if(n == 6)
    {
        cout << "2 5 29 2 5 29";
	}
    else if (n == 2)
    {
        cout << -1;
    }
    else
    {
        if (n == 5)
        {
            cout << "2 2 2 3 3";
        }
        else if (n % 2 == 0)
        {
            // 짝수
            cout << "2 2 2 3 3 2 2 2";

            n -= 8;
            for (int i = 0; i < n; i++)
                cout << " 3";
        }
        else
        {
            // 홀수
			cout << "2 2 2 3 3 3 3";
            n -= 7;
            for (int i = 0; i < n; i++)
				cout << " 3";
        }
    }
   
    return 0;
}
