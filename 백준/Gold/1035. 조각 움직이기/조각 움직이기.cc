#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int answer = 0;
vector<vector<char>> board;
vector<pair<int, int>> pos;
vector<bool> visited;

vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, -1, 1 };
int pos_count;

int CheckBoard(int x, int y, vector<int>& arr, vector<pair<int, int>>& check_point, int index)
{
    if (index == arr.size())
    {
        return 0;
    }

    queue<tuple<int, int, int>> q;
	vector<vector<bool>> visited(5, vector<bool>(5, false));

	q.push({ pos[arr[index]].first, pos[arr[index]].second, 0 });
	visited[pos[arr[index]].first][pos[arr[index]].second] = true;

    int result = -1;
	int min_dist = 1e9;

    while (!q.empty())
    {
		tuple<int, int, int> cur = q.front();
		int cur_x = get<0>(cur);
		int cur_y = get<1>(cur);
		int cur_dist = get<2>(cur);
        q.pop();

        if (cur_x == x && cur_y == y)
        {
            result = cur_dist;
            break;
		}

        for(int i = 0; i < 4; i++)
        {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];


            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visited[nx][ny] || board[nx][ny] == '*') continue;
			visited[nx][ny] = true;

            q.push({ nx, ny, cur_dist + 1 });   
		}
    }

    if (result == -1) return 1e9;

	board[pos[arr[index]].first][pos[arr[index]].second] = '.';
	board[x][y] = '*';
	check_point.push_back({ x, y });
    for(auto cp : check_point)
    {
		int cx = cp.first;
		int cy = cp.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || (board[nx][ny] == '*' && index + 1 < arr.size() && (pos[arr[index + 1]].first != nx || pos[arr[index + 1]].second != ny))) continue;

            min_dist = min(min_dist, CheckBoard(nx, ny, arr, check_point, index + 1));
        }
	}
	check_point.pop_back();
	board[pos[arr[index]].first][pos[arr[index]].second] = '*';
	board[x][y] = '.';

	return result + min_dist;
}

void travel(int cur, vector<int>& arr)
{
    if(arr.size() == pos_count)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if((board[i][j] == '*' && (pos[arr[0]].first != i || pos[arr[0]].second != j))) continue;
				vector<pair<int,int>> check_point;
				int value = CheckBoard(i, j, arr, check_point, 0);
                answer = min(answer, value);
            }
        }
        return;
	}

    for (int i = 0; i < pos_count; i++)
    {
        if (!visited[i])
        {
			visited[i] = true;
			arr.push_back(i);
			travel(i, arr);
			visited[i] = false;
			arr.pop_back();
        }
    }
}

int main() {
    FAST;

	board.resize(5);
	answer = 1e9;
    for (int i = 0; i < 5; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < 5; j++) {
            board[i].push_back(s[j]);
            if (s[j] == '*')
            {
                pos.push_back({ i, j });
				pos_count++;
            }
        }
    }

	visited.resize(pos_count, false);

    for (int i = 0; i < pos_count; i++)
    {
        if (!visited[i])
        {
            vector<int> arr;
            visited[i] = true;
            arr.push_back(i);
            travel(i, arr);
            visited[i] = false;
            arr.pop_back();
        }
    }

    cout << answer;


    return 0;
}
