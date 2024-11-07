#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

typedef long long ll;

int dp[1001][1001][4];

int main() {
    FAST;
    int real, imaginary;
    int target_real, target_imaginary;

    cin >> real >> imaginary;
    cin >> target_real >> target_imaginary;


    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= 1000; ++j) {
            for (int k = 0; k < 4; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }

    queue<tuple<int, int, int>> bfs;
    bfs.push({ real, imaginary, 0});
    dp[0][0][0] = 0;

    while (!bfs.empty()) {
        auto cur = bfs.front();
        bfs.pop();

        int cur_real, cur_imaginary, depth;
        tie(cur_real, cur_imaginary, depth) = cur;

        pair<int, int> next[3] = { {cur_real + 1, cur_imaginary},{ cur_real * 2 , cur_imaginary * 2}, {-cur_imaginary, cur_real } };

        for (auto& n : next) {
            if (n.first > 500 || n.first < -500 || n.second > 500 || n.second < -500) continue;
            int next_depth = depth + 1;

            //복소수는 4번 곱해주면 반복된다
            if (dp[n.first + 500][n.second + 500][next_depth % 4] == -1) {
                dp[n.first + 500][n.second + 500][next_depth % 4] = next_depth;
                bfs.push({ n.first, n.second, next_depth });
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int n;
        cin >> n;

        int value = dp[target_real + 500][target_imaginary + 500][n % 4];
        if (value != -1 && value <= n) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}