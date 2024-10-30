#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

vector<vector<int>> visited;
vector<vector<vector<bool>>> go;
vector<vector<int>> board;

//오른쪽 왼쪽 위 아래
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
int result = 0;

int GetDirection(int r1, int c1, int r2, int c2) {
    int r = r1 - r2;
    int c = c1 - c2;
    if (r == 0) return (c < 0) ? 0 : 1; // 오른쪽, 왼쪽
    return (r < 0) ? 3 : 2; // 아래, 위
}
int main() {
    Fast;
    int n, K, R;
    cin >> n >> K >> R;

    go.resize(n + 1, vector<vector<bool>>(n + 1, vector<bool>(4, false)));
    board.resize(n + 1, vector<int>(n + 1, 0));
    visited.resize(n + 1, vector<int>(n + 1, false));

    for (int i = 0; i < R; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int dir = GetDirection(r1, c1, r2, c2);
        int reverse = GetDirection(r2, c2, r1, c1);

        go[r1][c1][dir] = true;
        go[r2][c2][reverse] = true;
    }

    vector<pair<int, int>> cows;
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
        cows.push_back({ r, c });
    }

    for(int k = 0; k < cows.size(); k++){
        int i = cows[k].first;
        int j = cows[k].second;

        if (visited[i][j]) continue;

        int count = 1;

        queue<pair<int, int>> s;
        s.push({ i, j });
        visited[i][j] = true;

        while (!s.empty()) {
            pair<int, int> top = s.front();
            s.pop();

            int cur_r = top.first;
            int cur_c = top.second;


            for (int k = 0; k < 4; k++) {
                int next_r = cur_r + dir[k][0];
                int next_c = cur_c + dir[k][1];

                if (next_r <= 0 || next_r > n || next_c <= 0 || next_c > n) continue;
                if (visited[next_r][next_c]) continue;
                if (go[cur_r][cur_c][k]) continue;
                visited[next_r][next_c] = true;
                if (board[next_r][next_c] == 1) {
                    count++;
                }
                s.push({ next_r, next_c });
            }
        }
        result += count * (count - 1) / 2;
    }

    result = K * (K - 1) / 2 - result;

    cout << result;
    return 0;
}