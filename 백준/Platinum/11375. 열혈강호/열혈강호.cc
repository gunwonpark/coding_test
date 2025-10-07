#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

vector<vector<int>> adj;
vector<int> connected;
int answer = 0;

vector<int> visited;

bool dfs(int cur)
{
    visited[cur] = 1;
    for(int next : adj[cur])
    {
        if (connected[next] == -1 || (visited[connected[next]] == 0 && dfs(connected[next])))
        {
            connected[next] = cur;
            return true;
        }
	}

    return false;
}

int main() {
    FAST;

    int n, m; cin >> n >> m;
    
	adj.resize(n + 1);
	connected.resize(m + 1, -1);

    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        for(int j = 0; j < num; j++) {
            int a; cin >> a;
            adj[i].push_back(a);
		}
	}

    for (int i = 1; i <= n; i++)
    {
        visited.assign(n + 1, 0);
        if (dfs(i))
        {
            answer++;
        }
    }

    cout << answer;
	

    return 0;
}
