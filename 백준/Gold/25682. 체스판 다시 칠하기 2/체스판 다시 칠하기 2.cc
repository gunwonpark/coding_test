#include <iostream>
#include <vector>
#include <queue>

#define INT_MAX       2147483647

using namespace std;

struct Solution {
    int x, y;
    char c;

	Solution(int x, int y, char c) {
		this->x = x;
		this->y = y;
		this->c = c;
	}
};

int Solutions(vector<vector<char>> map, char c, int n, int m, int k) {
    vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
    vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> pdp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    queue<Solution> q;

    q.push(Solution(0, 0, c));

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int c = q.front().c;

        q.pop();

        if (x < 0 || x >= n || y < 0 || y >= m) {
            continue;
        }

        if (visited[x][y]) {
            continue;
        }

        visited[x][y] = true;

        if (c != map[x][y]) {
            dp[x + 1][y + 1] = 1;
        }

        int notC = c == 'B' ? 'W' : 'B';

        q.push(Solution(x + 1, y, notC));
        q.push(Solution(x, y + 1, notC));
    }

    int answer = INT_MAX;



    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j < dp[0].size(); ++j) {
            pdp[i][j] = pdp[i - 1][j] + pdp[i][j - 1] - pdp[i - 1][j - 1] + dp[i][j];
        }
    }

    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= m; ++j) {
            int cnt = pdp[i][j] - pdp[i - k][j] - pdp[i][j - k] + pdp[i - k][j - k];
            answer = min(answer, cnt);
        }
    }

    return answer;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> map = vector<vector<char>>(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
        for (int j = 0; j < m; j++) {
			map[i][j] = str[j];
		}
	}
    
	int answer = Solutions(map, 'B', n, m, k);
	answer = min(answer, Solutions(map, 'W', n, m, k));
    
	cout << answer << endl;
    
    return 0;
}

