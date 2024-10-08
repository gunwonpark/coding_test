#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<deque>
#include<unordered_set>
#include<unordered_map>
#include<cmath>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

int board[10][10];
int col[10][10];
int row[10][10];
int square[10][10];




void renewal(int number, int y, int x) {
	row[y][number]++;
	col[x][number]++;
	square[(y - 1) / 3 * 3 + (x - 1) / 3 + 1][number]++;
}

void erase(int number, int y, int x) {
	row[y][number]--;
	col[x][number]--;
	square[(y - 1) / 3 * 3 + (x - 1) / 3 + 1][number]--;
}

bool travel(int num) {
	if (num == 81) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (board[i][j] == 0) {
					return false;
				}
			}
		}
		
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << board[i][j];
			}
			cout << '\n';
		}
		return true;
	}

	int y = num / 9 + 1;
	int x = num % 9 + 1;

	if (board[y][x] != 0) {
		if (travel(num + 1)) {
			return true;
		}
		else {
			return false;
		}
	}
	
	for (int i = 1; i <= 9; i++) {
		if (row[y][i] == 0 && col[x][i] == 0 && square[(y - 1) / 3 * 3 + (x - 1) / 3 + 1][i] == 0) {
			board[y][x] = i;
			renewal(i, y, x);
			if (travel(num + 1)) {
				return true;
			}
			board[y][x] = 0;
			erase(i, y, x);
		}
	}

	return false;
}

int main() {
	Fast;
	
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			char c;
			cin >> c;
			board[i][j] = c - '0';
			row[i][board[i][j]]++;
			col[j][board[i][j]]++;
			square[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][board[i][j]]++;
		}
	}

	travel(0);

	return 0;
	
}