#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;
vector<vector<pair<int, int>>> arr;
vector<int> visited;
int answer = 0;

void dfs(int least, int cur, int value) {
    visited[cur] = true;

    for (int i = 0; i < arr[cur].size(); i++) {
        int next = arr[cur][i].first;
        int next_value = arr[cur][i].second;

        if (visited[next]) continue;

        if (next_value <= value) {
            if (next_value >= least) answer++;
            dfs(least, next, next_value);
        }
        else {
            if (value >= least) answer++;
            dfs(least, next, value);
        }
    }

    visited[cur] = false;
    return;
}
int main() {
    Fast;

    int n, q;
    cin >> n >> q;

    arr.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int q, p, r;
        cin >> q >> p >> r;
        arr[q].push_back({ p, r });
        arr[p].push_back({ q , r });
    }

    while (q--) {
        int k, v;
        cin >> k >> v;

        dfs(k, v, 1000000001);
        cout << answer << '\n';
        answer = 0;
    }


    return 0;
}