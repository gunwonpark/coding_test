#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int result = 0;
//board의 값이 변경되지 않도록 복사본 생성

//상 하 좌 우 각각의 움직임에따른 값의 변화
vector<vector<int>> Right(vector<vector<int>> board) {
	for (int i = 0; i < N; i++)
	{
		int non_zero = 0;
		int k = N - 1;
		int* first = new int[2];
		for (int j = N - 1; j >= 0; j--)
		{
			if (board[i][j] != 0)
			{
				first[non_zero] = board[i][j];
				non_zero += 1;
				if (non_zero == 2)
				{
					if (first[0] == first[1])
					{
						board[i][k] = first[0] + first[1];
						k--;
					}
					else
					{
						board[i][k] = first[0];
						k--;
						j += 1;
					}
					non_zero = 0;
				}
			}
		}
		if (non_zero == 1)
		{
			board[i][k] = first[0];
			k--;
		}

		for (int j = k; j >= 0; j--) {
			board[i][j] = 0;
		}
		delete[] first;
	}
	return board;
}

vector<vector<int>> Left(vector<vector<int>> board) {
	for (int i = 0; i < N; i++)
	{
		int non_zero = 0;
		int k = 0;
		int* first = new int[2];
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] != 0)
			{
				first[non_zero] = board[i][j];
				non_zero += 1;
				if (non_zero == 2)
				{
					if (first[0] == first[1])
					{
						board[i][k] = first[0] + first[1];
						k++;
					}
					else
					{
						board[i][k] = first[0];
						k++;
						j -= 1;
					}
					non_zero = 0;
				}
			}
		}
		if (non_zero == 1)
		{
			board[i][k] = first[0];
			k++;
		}

		for (int j = k; j < N; j++) {
			board[i][j] = 0;
		}
		delete[] first;
	}
	return board;
}

vector<vector<int>> Down(vector<vector<int>> board) {
	for (int i = 0; i < N; i++)
	{
		int non_zero = 0;
		int k = N - 1;
		int* first = new int[2];
		for (int j = N - 1; j >= 0; j--)
		{
			if (board[j][i] != 0)
			{
				first[non_zero] = board[j][i];
				non_zero += 1;
				if (non_zero == 2)
				{
					if (first[0] == first[1])
					{
						board[k][i] = first[0] + first[1];
						k--;
					}
					else
					{
						board[k][i] = first[0];
						k--;
						j += 1;
					}
					non_zero = 0;
				}
			}
		}
		if (non_zero == 1)
		{
			board[k][i] = first[0];
			k--;
		}

		for (int j = k; j >= 0; j--) {
			board[j][i] = 0;
		}
		delete[] first;
	}
	return board;
}

vector<vector<int>> Up(vector<vector<int>> board) {
	for (int i = 0; i < N; i++)
	{
		int non_zero = 0;
		int k = 0;
		int* first = new int[2];
		for (int j = 0; j < N; j++)
		{
			if (board[j][i] != 0)
			{
				first[non_zero] = board[j][i];
				non_zero += 1;
				if (non_zero == 2)
				{
					if (first[0] == first[1])
					{
						board[k][i] = first[0] + first[1];
						k++;
					}
					else
					{
						board[k][i] = first[0];
						k++;
						j -= 1;
					}
					non_zero = 0;
				}
			}
		}
		if (non_zero == 1)
		{
			board[k][i] = first[0];
			k++;
		}

		for (int j = k; j < N; j++) {
			board[j][i] = 0;
		}
		delete[] first;
	}
	return board;
}
//board판에서 가장 큰 수 찾기
int get_max_2048(vector<vector<int>> board) {
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (max < board[i][j])
				max = board[i][j];
		}
	}
	return max;
}

void play_game(int count,  vector<vector<int>> board) {
	//5번의 동작이 끝나면 가장 큰 결과 저장 후 보드판 리셋
	if (count == 5) {
		result = max(result, get_max_2048(board));			
		return;
	}
	//5번의 동작 재귀로 모두 탐색 ex) 상상상상하
	else {
		for (int i = 0; i < 4; i++) {
			if(i == 0)		
				play_game(count + 1, Up(board));
			else if(i == 1)
				play_game(count + 1, Down(board));
			else if(i == 2)
				play_game(count + 1, Left(board));
			else			
				play_game(count + 1, Right(board));
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	//보드판 가져오기
	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	play_game(0, board);

	cout << result;
	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}*/
}

