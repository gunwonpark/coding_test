#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using ll = long long;

using namespace std;



int main() {
    Fast;
    
    // bfs로 깊이별로 몇개의 갚이 있는지 확인하다
    // 깊이가 n 이라면 
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 

    int max_depth = 0;

    for (int i = 1; i <= n; ++i) {
        vector<bool> visited(n + 1);
        queue<pair<int, int>> q;
        int temp_max_depth = 0;
        q.push({ i, 1 });
        visited[i] = true;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int index = cur.first;
            int depth = cur.second;

            temp_max_depth = depth;

            for (int i = 0; i < adj[index].size(); ++i) {
                int next = adj[index][i];

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({ next, depth + 1 });
                }
            }
        }
        max_depth = max(temp_max_depth, max_depth);
    }

    if (max_depth == 2 || max_depth == 3) {
        cout << n - 1;
    }
    else {
        cout << n;
    }

    return 0;
}