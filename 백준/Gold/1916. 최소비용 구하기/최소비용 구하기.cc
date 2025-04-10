#include<bits/stdc++.h>

//c++17 version

using namespace std;
#define FA ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int n, m;
vector<vector<pair<ll, ll>>> arr;
vector<int> visited;

int calcDistance(int start, int dest) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({ 0, start });

    while (!pq.empty())
    {
        pair<ll, ll> p = pq.top();
        pq.pop();

        ll cost = p.first;
        ll node = p.second;

        if (visited[node]) continue;

        visited[node] = 1;

        for (auto i : arr[node])
        {
            if (!visited[i.first])
            {
                pq.push({ cost + i.second, i.first });
            }
        }

        if (node == dest) {
            return cost;
        }
    }

    return -1;
}

int main() {
    FA;

    cin >> n >> m;
    arr.resize(n + 1);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        arr[a].push_back({ b, c });
    }

    ll pa1, pa2;
    cin >> pa1 >> pa2;

    visited.resize(n + 1, 0);

    ll an = calcDistance(pa1, pa2);    

    
	cout << an;

    return 0;
}