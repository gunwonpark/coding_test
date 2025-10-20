#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

vector<int> nums;
vector<vector<int>> adj;
vector<int> visited;
vector<ll> counts;
ll mod = 1e9 + 7;
ll answer = 0;

ll CalcIncreaseSubarrays(vector<int>& arr)
{
    int index = arr.back();
    ll result = 1;
    
    for(int i = index; i >= 0; i--)
    {
        result += counts[i];
	}

    return result;
}

void Dfs(int node, vector<int>& trace)
{
	visited[node] = 1;
    
	trace.push_back(nums[node]);
	ll result = CalcIncreaseSubarrays(trace);
    result %= mod;
    answer += result;
	int oldValue = counts[nums[node]];
    counts[nums[node]] += result;
	counts[nums[node]] %= mod;
    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            Dfs(neighbor, trace);
        }
	}
	trace.pop_back();
    counts[nums[node]] = oldValue;

    return;
}

int main() {
    FAST;
    int n; cin >> n;
	nums.resize(n + 1);
	adj.resize(n + 1);
	visited.resize(n + 1, 0);
    counts.resize(10, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> trace;
    Dfs(1, trace);

	cout << answer % mod << "\n";
    return 0;
}
