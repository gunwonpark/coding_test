#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

int n;
vector<vector<int>> board;
int blue_result = 0;
int white_result = 0;

void solve(int start_x, int start_y, int end_x, int end_y) {
    int mid_x = (start_x + end_x) / 2;
    int mid_y = (start_y + end_y) / 2;

    int calc_blue = 0;
    int calc_white = 0;

    for (int i = start_x; i <= end_x; i++) {
        for (int j = start_y; j <= end_y; j++) {
            if (board[i][j] == 1) {
				calc_blue++;
            }
            else {
				calc_white++;
			}
		}
    }

    if (calc_blue == 0) {
        white_result++;
        return;
    }
    else if (calc_white == 0) {
		blue_result++;
		return;
	}

    solve(start_x, start_y, mid_x, mid_y);
    solve(start_x, mid_y + 1, mid_x, end_y);
    solve(mid_x + 1, start_y, end_x, mid_y);
    solve(mid_x + 1, mid_y + 1, end_x, end_y);
}
int main() {
    FAST;

    cin >> n;
    board.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {		
        for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

    solve(0, 0, n - 1, n - 1);

    cout << white_result << "\n" << blue_result << "\n";

    return 0;
}