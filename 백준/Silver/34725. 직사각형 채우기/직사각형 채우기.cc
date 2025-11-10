#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;
	
    int n, m; cin >> n >> m;
    int width = n / 2;
    int height = m / 2;
    vector<vector<int>> board(n, vector<int>(m));

    for (int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            int cur = 1 + (i * height + j);
            board[i][j] = cur;
            board[i][j + height] = cur;
			board[i + width][j] = cur;
			board[i + width][j + height] = cur;
		}
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
	}

    return 0;
}
