#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int check[50][50];
int board[50][50];
int n;

struct Node {
    int value, x, y;
    Node(int value, int x, int y) : value(value), x(x), y(y) {}

    bool operator<(const Node& node) const {
        return value > node.value;
    }
};
void solve() {
    priority_queue<Node> pq;
    pq.push(Node(0, 0, 0));

    while (!pq.empty()) {
        int curX = pq.top().x;
        int curY = pq.top().y;
        int curValue = pq.top().value;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dir[i][0];
            int nextY = curY + dir[i][1];

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
            if (check[nextX][nextY] == -1) {
                check[nextX][nextY] = curValue + board[nextX][nextY];
                pq.push(Node(check[nextX][nextY], nextX, nextY));
            }
            
        }
    }
}

int main() {
    FAST;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            int num = str[j] - '0';
            board[i][j] = abs(num - 1);
		}
	}
    memset(check, -1, sizeof(check));
    solve();
    cout << check[n - 1][n - 1] << '\n';
    return 0;
}