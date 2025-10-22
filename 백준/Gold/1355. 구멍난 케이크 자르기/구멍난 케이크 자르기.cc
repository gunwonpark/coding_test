#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void dfs(vector<vector<int>>& board, int x, int y)
{
    board[x][y] = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board.size()) continue;
        if(board[nx][ny] == 1)
        {
            dfs(board, nx, ny);
        }
	}
}

int main() {
    FAST;
    int n, m; cin >> n >> m;

    vector<vector<int>> board(4 * n + 1, vector<int>(4 * n + 1, 1));

    int mid = board.size() / 2;

    for (int i = mid - 2 * m; i <= mid + 2 * m; i++)
    {
        for (int j = mid - 2 * m; j <= mid + 2 * m; j++)
        {
            board[i][j] = 0;
        }
    }

    int h; cin >> h;
    for (int i = 0; i < h; i++) {
        int cut; cin >> cut;

        int keyPoint = mid + 2 * cut;

        for (int j = 0; j < board.size(); j++)
        {
            board[keyPoint][j] = 0;
        }
    }

    int v; cin >> v;
    for (int i = 0; i < v; i++) {
        int cut; cin >> cut;

        int keyPoint = mid + 2 * cut;

        for (int j = 0; j < board.size(); j++)
        {
            board[j][keyPoint] = 0;
        }
    }

    int answer = 0;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == 1)
            {
                answer++;
                dfs(board, i, j);

                /*for (int x = 0; x < board.size(); x++)
                {
                    for (int y = 0; y < board.size(); y++)
                    {
                        cout << board[x][y];
                    }
                    cout << '\n';
                }

                cout << '\n';*/
            }
        }
    }

    
	cout << answer << '\n';


    return 0;
}
