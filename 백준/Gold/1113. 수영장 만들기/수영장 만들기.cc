#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<bool>> visited;
set<pair<int, int>> changed;

int answer = 0;

void fill(int num)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(board[i][j] == num)
			{
				changed.insert({ i, j });
				board[i][j] = num + 1;
				answer++;
			}
		}
	}
}

void travel(int x, int y, int key)
{
	int min_height = 10;
	bool is_delete = false;
	queue<pair<int, int>> q;
	vector<pair<int, int>> temp;
	q.push({ x, y });
	temp.push_back({ x, y });
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	while(!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for(int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				is_delete = true;
				continue;
			}
			if(visited[nx][ny]) continue;
			if(board[nx][ny] == key && changed.find({ nx, ny }) != changed.end())
			{
				visited[nx][ny] = true;
				q.push({ nx, ny });
				temp.push_back({ nx, ny });
			}
			else
			{
				min_height = min(min_height, board[nx][ny]);
			}
		}
	}

	if (is_delete == false && min_height >= key)
	{
		return;
	}
	else
	{
		for(int i = 0; i < temp.size(); i++)
		{
			int tx = temp[i].first;
			int ty = temp[i].second;
			if(changed.find({ tx, ty }) != changed.end())
			{
				board[tx][ty]--;
				answer--;
			}
		}
	}
	return;
}

void check_ans_delete(int num)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(visited[i][j] == false && board[i][j] == num && changed.find({ i, j }) != changed.end())
			{
				visited[i][j] = true;
				travel(i, j, num);
			}
		}
	}
}

int main() {
    FAST;
	cin >> n >> m;
	board.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	for (int i = 1; i < 9; i++)
	{
		visited.assign(n, vector<bool>(m, false));
		changed.clear();
		// i층 높이를 채워본다.
		fill(i);
		// i + 1층 높이가 유지 될 수 있는지 확인한다.
		check_ans_delete(i + 1);
	}
    
	cout << answer << "\n";

    return 0;
}
