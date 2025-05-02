#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

struct Info {
    int r, c, index;
    Info() : Info(0, 0, 0) {};
    Info(int r, int c, int index) : r(r), c(c), index(index) {};
};

int main(){ 
    FAST;

    int r, c; cin >> r >> c;
    vector<vector<char>> arr(r, vector<char>(c, 0));

    queue<Info> jPos;
    queue<Info> fPos;

    vector<vector<int>> isFire(r, vector<int>(c, 0));
    vector<vector<int>> visited(r, vector<int>(c, 0));
    vector<vector<int>> isDead(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        string input; cin >> input;
        for (int j = 0; j < c; j++) {
            arr[i][j] = input[j];

            if (arr[i][j] == 'J') {
                jPos.push(Info(i, j, 1));
                visited[i][j] = 1;
            }
            
            if(arr[i][j] == 'F'){
                fPos.push(Info(i, j, 1));
                isFire[i][j] = 1;
            }
        }
    }

    int dir[4][2] = { {0,1}, {0,-1},{1, 0},{-1,0} };

    int count = 0;

    while (true) {
        count++;
        // player 이동
        while (!jPos.empty()) {
            Info playerPos = jPos.front();
            if (count == playerPos.index) break;
            jPos.pop();

            if (isDead[playerPos.r][playerPos.c]) {
                continue;
            }


            for (int i = 0; i < 4; i++) {
                int nextR = playerPos.r + dir[i][0];
                int nextC = playerPos.c + dir[i][1];

                if (nextR < 0 || nextR >= r || nextC < 0 || nextC >= c) {
                    cout << playerPos.index;
                    return 0;
                }
                if (arr[nextR][nextC] == '#' || isFire[nextR][nextC] || visited[nextR][nextC]) continue;

                visited[nextR][nextC] = 1;
                jPos.push(Info(nextR, nextC, playerPos.index + 1));
            }
        }

        while (!fPos.empty()) {
            Info firePos = fPos.front();
            if (count == firePos.index) break;
            fPos.pop();


            for (int i = 0; i < 4; i++) {
                int nextR = firePos.r + dir[i][0];
                int nextC = firePos.c + dir[i][1];

                if (nextR < 0 || nextR >= r || nextC < 0 || nextC >= c) {
                    continue;
                }

                if (arr[nextR][nextC] == '#' || isFire[nextR][nextC]) continue;
                if (visited[nextR][nextC]) {
                    isDead[nextR][nextC] = 1;
                }

                isFire[nextR][nextC] = 1;
                fPos.push(Info(nextR, nextC, firePos.index + 1));
            }
        }

        if (jPos.empty())
            break;
    }

    cout << "IMPOSSIBLE";

    return 0;
}