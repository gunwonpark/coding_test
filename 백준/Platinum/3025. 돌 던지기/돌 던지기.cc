#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

// 바닥의 위치와 쌓여있는 돌의 개수를 저장해 둔다
struct Floor {
    int position, rock_count;
    Floor(int position, int rock_count) :position(position), rock_count(rock_count) {};
    Floor() { position = 0; rock_count = 0; };
    
    bool operator < (const Floor& cmp) const{
        return position < cmp.position;
    }
};

int R, C;
vector<vector<char>> board;
vector<vector<Floor>> _floor;
vector<stack<pair<int,int>>> check_point;
void print() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    cout << '\n';
    return;
}

pair<int, int> find_closest_row(int r, int c) { 
    // 돌을 놓을수 있는 공간을 빠르게 구한다
    int index = lower_bound(_floor[c].begin(), _floor[c].end(), Floor(r, 0)) - _floor[c].begin();

    int position = _floor[c][index].position;
    int rock_count = _floor[c][index].rock_count;

    return { position - rock_count - 1, index };
}

pair<int, int> find_next_pos(int r, int c) {
    //아래 확인
    int down_r = r + 1;
    
    if (board[down_r][c] == 'X') return { r, c };
    //돌일경우와 빈 공간일 경우 구분
    if (board[down_r][c] == 'O') {
        //왼쪽 우선 확인
        int left_c = c - 1;
        int right_c = c + 1;
        if (left_c >= 0 && board[r][left_c] == '.' && board[down_r][left_c] == '.') return { down_r, left_c };
        if (right_c < C && board[r][right_c] == '.' && board[down_r][right_c] == '.') return { down_r, right_c };
        return { r,c };
    }
    else {
        return { down_r, c };
    }
}

void do_simulation(int r, int c , int start_c) {
    pair<int, int> res = find_closest_row(r, c);
    r = res.first;
    int index = res.second;


    if (r == R - 1) {
        board[r][c] = 'O';
        _floor[c].back().rock_count++;
        return;
    }
    pair<int, int> next_pos = find_next_pos(r, c);
    check_point[start_c].push({r, c});

    if (next_pos.first == r && next_pos.second == c) {
        board[r][c] = 'O';
        _floor[c][index].rock_count++;
        check_point[start_c].pop();
        return;
    }
    do_simulation(next_pos.first, next_pos.second, start_c);
}

void simulate(int col) {
    int start_r = 0;
    int start_c = col;

    while (!check_point[start_c].empty()) {
        pair<int, int> top = check_point[start_c].top();
        int check_r = top.first;
        int check_c = top.second;

        if (board[check_r][check_c] == '.') {
            start_r = check_r;
            start_c = check_c;
            break;
        }

        check_point[start_c].pop();
    }

    do_simulation(start_r, start_c, col);    
    return;
}

int main() {
    Fast;

    cin >> R >> C;

    board.resize(R, vector<char>(C));
    _floor.resize(C);
    check_point.resize(C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            //바닥일 경우 표시를 해둔다
            if (board[i][j] == 'X') {
                _floor[j].push_back({ i, 0 });
            }
        }
    }

    // 제일 밑을 바닥으로 취급한다
    for (int i = 0; i < C; i++) {
        _floor[i].push_back({ R, 0 });
    }

    int query;
    cin >> query;
    while (query--) {
        int input;
        cin >> input;

        int col = input - 1;

        simulate(col);
    }
    
    print();
    return 0;
}