#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;



int r, c;
string result;
vector<vector<int>> board;


int main() {    
    cin >> r >> c;
    int minValue = 1001;
    int minValueX = 0;
    int minValueY = 0;
    board.resize(r + 1, vector<int>(c + 1, 0));

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
            if ((i == 1 && j == 1) || (i == r && j == c)) continue;
           
            //짝짝 홀홀 무시
            if ((i % 2) == (j % 2)) continue;

            if (minValue > board[i][j]) {
                minValue = board[i][j];
                minValueY = i;
                minValueX = j;
            }
		}
	}

    // 둘중 하나라도 짝수인 경우는 완전 탐색으로 해결 가능하다
    // 열이 홀수인 경우
    if (r % 2 == 1) {
        //오른쪽 부터 탐색
        char dir = 'R';
        int length = r * c;
        for (int i = 1; i < length; i++) {
            if (i % c == 0) {
                cout << 'D';
                dir = (dir == 'R') ? 'L' : 'R';
            }
            else {
				cout << dir;
			}
		}
    }
    else if (c % 2 == 1) {
		// 아래쪽 부터 탐색
        //오른쪽 부터 탐색
        char dir = 'D';
        int length = r * c;
        for (int i = 1; i < length; i++) {
            if (i % r == 0) {
                cout << 'R';
                dir = (dir == 'D') ? 'U' : 'D';
            }
            else {
                cout << dir;
            }
        }
	}
    // 둘다 짝수인 경우 완전 탐색이 불가능 하다
    else {
        // 가장 작은 값의 행 열이 짝 홀 or 홀 짝인 경우 그 공간만 희생하고 탐색하면 된다
        // 아닐 경우 어처피 짝 홀 칸을 희생해야 되는건 마찬가지므로 다음 짝홀 칸을 찾는다
        // minRow가 홀수 일경우 그 row부터 아래 오른쪽 위를 반복 탐색
        // minRow가 짝수 일경우 그 row 위부터 아래 오른쪽 위 반복 탐색
        char search[4] = { 'D', 'R', 'U', 'R'};
        int searchIndex = 0;
        int errorPos = (minValueX - 1) * 2;
        bool addOnce = true;
        int count = 0;
        if (minValueY % 2 == 1) {
            //오른쪽 부터 탐색
            char dir = 'R';
            int length = r * c;
            for (int i = 1; i < length; i++) {
                if (i / c == minValueY - 1 || i / c == minValueY) {
                    count++;
                    if (count == 2 * (c - 1)) {
                        i++;
                    }
                    if (minValueY != 1 && addOnce) {
                        cout << 'D';
                        dir = (dir == 'R') ? 'L' : 'R';
                        addOnce = false;
                        continue;
                    }
                    if (searchIndex == errorPos) {
                        cout << 'R';
                        errorPos = -1;
                        continue;
                    }
                    cout << search[searchIndex % 4];
                    searchIndex++;
                    
                    
                    continue;
                }
                if (i % c == 0) {
                    cout << 'D';
                    dir = (dir == 'R') ? 'L' : 'R';
                }
                else {
                    cout << dir;
                }
            }
        }
        else {
            //오른쪽 부터 탐색
            char dir = 'R';
            int length = r * c;
            for (int i = 1; i < length; i++) {
                if (i / c == minValueY - 2 || i / c == minValueY - 1) {
                    count++;
                    if (count == 2 * (c - 1)) {
                        i++;
                    }
                    if (minValueY != 1 && addOnce) {
                        cout << 'D';
                        dir = (dir == 'R') ? 'L' : 'R';
                        addOnce = false;
                        continue;
                    }
                    if (searchIndex == errorPos) {
                        cout << 'R';
                        errorPos = -1;
                        continue;
                    }
                    cout << search[searchIndex % 4];
                    searchIndex++;

                    
                    continue;
                }
                if (i % c == 0) {
                    cout << 'D';
                    dir = (dir == 'R') ? 'L' : 'R';
                }
                else {
                    cout << dir;
                }
            }
        }
    }
    
    return 0;
}
