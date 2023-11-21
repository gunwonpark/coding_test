#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;


class Dp {
private:
    int a, b, c; 
    int dp[21][21][21];

public:
    Dp() {
        a = 0; b = 0; c = 0;
    }
    void Init() {
        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 21; j++) {
                for (int k = 0; k < 21; k++) {
                    dp[i][j][k] = 1;
                }
            }
        }

        for (int i = 1; i < 21; i++) {
            for (int j = 1; j < 21; j++) {
                for (int k = 1; k < 21; k++) {
                    if (i < j && j < k)
                        dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k] - dp[i][j - 1][k];
                    else
                        dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
                }
            }
        }
    }

    void solution() {
        while (true) {
            cin >> a >> b >> c;
            if (terminationCondition())
                return;
            //todo
            printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
        }        
    }

    bool terminationCondition() {
        if (a == -1 && b == -1 && c == -1)
            return true;

        return false;
    }
   
    int w(int a,int b, int c) {
        if (a <= 0 || b <= 0 || c <= 0)
            return 1;
        if (a > 20 || b > 20 || c > 20)
            return dp[20][20][20];
        else
            return dp[a][b][c];
    }
   
};

int main() {
    sync;
    Dp dp;
    dp.Init();
    dp.solution();
    return 0;
}

