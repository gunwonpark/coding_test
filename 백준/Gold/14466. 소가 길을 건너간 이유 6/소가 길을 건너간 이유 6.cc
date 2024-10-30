#include <bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

vector<vector<int>> visited;
vector<vector<vector<bool>>> go;
vector<vector<int>> board;

// 방향 정보 (오른쪽, 왼쪽, 위, 아래)
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

// 방향을 구하는 함수
int GetDirection(int r1, int c1, int r2, int c2) {
    int r = r1 - r2;
    int c = c1 - c2;
    if (r == 0) return (c < 0) ? 0 : 1; // 오른쪽, 왼쪽
    return (r < 0) ? 3 : 2; // 아래, 위
}

// BFS를 통해 그룹에 속한 소의 수를 구함
int BFS(int start_r, int start_c, int n) {
    queue<pair<int, int>> q;
    q.push({ start_r, start_c });
    visited[start_r][start_c] = true;

    int cow_count = 1;  // 시작 위치에 소가 있는 상태
    while (!q.empty()) {
        auto [cur_r, cur_c] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int next_r = cur_r + dir[k][0];
            int next_c = cur_c + dir[k][1];

            // 유효 범위 확인, 방문 여부, 길 존재 여부 체크
            if (next_r <= 0 || next_r > n || next_c <= 0 || next_c > n) continue;
            if (visited[next_r][next_c] || go[cur_r][cur_c][k]) continue;

            visited[next_r][next_c] = true;
            if (board[next_r][next_c] == 1) cow_count++;
            q.push({ next_r, next_c });
        }
    }
    return cow_count;
}

int main() {
    Fast;
    int n, k, R;
    cin >> n >> k >> R;

    go.resize(n + 1, vector<vector<bool>>(n + 1, vector<bool>(4, false)));
    board.resize(n + 1, vector<int>(n + 1, 0));
    visited.resize(n + 1, vector<int>(n + 1, false));

    // 길 정보 입력
    for (int i = 0; i < R; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int dir = GetDirection(r1, c1, r2, c2);
        int reverse = GetDirection(r2, c2, r1, c1);

        go[r1][c1][dir] = true;
        go[r2][c2][reverse] = true;
    }

    // 소 위치 입력
    vector<pair<int, int>> cows;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
        cows.push_back({ r, c });
    }

    ll total_pairs = (ll)k * (k - 1) / 2;  // 전체 소 쌍
    ll same_group_pairs = 0;  // 같은 그룹 내 소 쌍 수

    // 각 소 위치에서 BFS를 통해 그룹 찾기
    for (auto [r, c] : cows) {
        if (!visited[r][c]) {
            int cow_count_in_group = BFS(r, c, n);
            same_group_pairs += (ll)cow_count_in_group * (cow_count_in_group - 1) / 2;
        }
    }

    // 서로 만나지 못하는 소 쌍 계산
    ll result = total_pairs - same_group_pairs;
    cout << result << '\n';

    return 0;
}