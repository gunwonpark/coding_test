#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

void print(vector<char>& s)
{
    for (char c : s)
    {
        cout << c;
    }
    cout << '\n';
}

int main() {
    FAST;

    int n, k; cin >> n >> k;
    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
	}

    for (int i = 0; i < n; i++)
    {
        int limit = s[i] - 'A';

        if (k > limit)
        {
            k -= limit;
        }
        else
        {
			s[i] = char('A' + k - 1);
            print(s);
			return 0;
        }
    }

    if (k == 1)
    {
        print(s);
        return 0;
    }

    k -= 1;
    
    for(int i = n - 1; i >= 0; i--)
    {
        int limit = 'Z' - s[i];
        if (k > limit)
        {
            k -= limit;
        }
        else
        {
            s[i] = char(s[i] + k);
			print(s);
            return 0;
        }
	}

	cout << -1 << '\n';
  

    return 0;
}
