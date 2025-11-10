#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;
	
    int n, m; cin >> n >> m;

    vector<string> board;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        board.push_back(s);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            char a = board[i][j];
			char b = board[i][j + 1];
			char c = board[i + 1][j];
			char d = board[i + 1][j + 1];

            if (a == b && a == c && a == d && a == '1')
            {
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;

    return 0;
}
