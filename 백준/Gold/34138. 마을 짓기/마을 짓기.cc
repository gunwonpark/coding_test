#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int n, m;
vector<vector<int>> visited;
vector<vector<int>> culDiagonal;
vector<vector<int>> culSquare;
vector<vector<char>> board;

vector<int> plusComponent;
vector<int> minusComponent;

// 주 대각선의 누적합 계산
void calculate_diagonal_sum()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c = board[i][j];
			int value = c == 'X' ? 1 : 0;

			culDiagonal[i + 1][j + 1] = culDiagonal[i][j] + value;
		}
	}
}

// 주 대각선 영역의 개수 찾기
int find_diagonal_count(int s_x, int s_y, int e_x, int e_y)
{
	return culDiagonal[e_x + 1][e_y + 1] - culDiagonal[s_x][s_y];
}

// 사각형의 누적합 계산
void calculate_square_sum()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c = board[i][j];
			int value = c == 'X' ? 1 : 0;
			culSquare[i + 1][j + 1] = value + culSquare[i][j + 1] + culSquare[i + 1][j] - culSquare[i][j];
		}
	}
}

// 사각형 영역의 개수 찾기
int find_square_count(int s_x, int s_y, int e_x, int e_y)
{
	return culSquare[e_x + 1][e_y + 1] - culSquare[s_x][e_y + 1] - culSquare[e_x + 1][s_y] + culSquare[s_x][s_y];
}

// 영역안이 주 대각선으로만 이루어져 있는지 확인
bool is_diagonal_only(int s_x, int s_y, int e_x, int e_y)
{
	int diagonal_count = find_diagonal_count(s_x, s_y, e_x, e_y);
	int square_count = find_square_count(s_x, s_y, e_x, e_y);

	if (diagonal_count == e_x - s_x + 1 && diagonal_count == square_count)
	{
		return true;
	}

	return false;
}

void travel(int x, int y, int jump)
{
	int k = min(n, m);

	for (int i = jump; i <= k; i++)
	{
		if (x + i >= n || y + i >= m || board[x + i][y + i] != 'X')
		{
			plusComponent[i]++;
			break;
		}

		if (!is_diagonal_only(x, y, x + i, y + i))
		{
			visited[x + i][y + i] = 1;

			plusComponent[i]++;

			// x + i, y + i 부터 왼쪽 위쪽에서 X가 아닌 가장 첫번째 위치를 찾는다.
			int left = y + i;
			int up = x + i;

			int length = k + 1;

			for (int j = 1; j <= i; j++)
			{
				if (board[up][left - j] == 'X')
				{
					length = min(length, j);
					break;
				}
			}

			for (int j = 1; j <= i; j++)
			{
				if (board[up - j][left] == 'X')
				{
					length = min(length, j);
					break;
				}
			}

			int new_x = x + i - length + 1;
			int new_y = y + i - length + 1;
			int jump = length;
			minusComponent[length - 1]++;
			
			travel(new_x, new_y, jump);
			break;
		}

		visited[x + i][y + i] = 1;
	}
}

// 가능한 개수 계산
void calculate_component()
{
	int k = min(n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'X' && visited[i][j] == 0)
			{
				visited[i][j] = 1;
				travel(i, j, 1);
			}
		}
	}
}

int main()
{
	FAST;
	cin >> n >> m;

	board.resize(n, vector<char>(m, 0));
	visited.resize(n, vector<int>(m, 0));
	culDiagonal.resize(n + 1, vector<int>(m + 1, 0));
	culSquare.resize(n + 1, vector<int>(m + 1, 0));

	int k = min(n, m);

	plusComponent.resize(k + 1, 0);
	minusComponent.resize(k + 1, 0);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	calculate_diagonal_sum();
	calculate_square_sum();

	calculate_component();

	vector<int> answer(k + 1, 0);

	for (int i = k; i >= 1; i--)
	{
		int num = plusComponent[i] - minusComponent[i];
		for (int j = 1; j <= i; j++)
		{
			answer[i - j + 1] += num * j;
		}
	}

	for (int i = 1; i <= k; i++)
	{
		cout << answer[i] << '\n';
	}

	return 0;
}