#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;


int main() {
    FAST;

    int n, m; cin >> n >> m;
    vector<ll> cols(m);
    vector<ll> rows(n);
	vector<vector<int>> board(n, vector<int>(m));

    ll answer = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x; cin >> x;
			board[i][j] = x;
            cols[j] += x;
            rows[i] += x;
        }
	}

    for (int _ = 0; _ < n + m; _++)
    {
        // 가장 작은 지점 찾기
        bool row = false;
        int min_index = -1;
        ll min_value = 1e18;
        for (int i = 0; i < max(n, m); i++)
        {
            if(i < n && rows[i] < min_value) {
                min_value = rows[i];
                min_index = i;
                row = true;
			}

            if (i < m && cols[i] < min_value) {
                min_value = cols[i];
                min_index = i;
                row = false;
            }
        }

        // 지점 업데이트
        if (row)
        {
			rows[min_index] = 1e18;
            for (int i = 0; i < m; i++)
            {
				if (cols[i] == 1e18) continue;
                cols[i] -= board[min_index][i];
            }
        }
        else
        {
			cols[min_index] = 1e18;
            for(int i = 0; i < n; i++) {
				if (rows[i] == 1e18) continue;
                rows[i] -= board[i][min_index];
			}
        }
        
		answer = max(answer, min_value);
    }

    cout << answer;

    return 0;
}
