#include<bits/stdc++.h>

//c++17 version

using namespace std;
#define FA ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FA;

    int n, k; cin >> n >> k;

    // 1 or i + i/2
    // 1 2 3 4 5 6 7 8 9 or
    // 0 1 3 4 6 7
    
    vector<int> vi(n + 1, 0);
    queue<pair<int, int>> q;
    q.push({0, 0});
    vi[0] = -1;    

    while (!q.empty())
    {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        int dir[2] = { cur + 1, cur + cur / 2 };

        if (time == k) {
            break;
        }

        for (int i = 0; i < 2; i++)
        {
			int next = dir[i];
			if (next > n) continue;
            if (vi[next] == 0)
            {
                vi[next] = -1;
				q.push({ next, time + 1 });
			}
		}
    }

    cout << (vi[n] == -1 ? "minigimbob" : "water");

    return 0;
}