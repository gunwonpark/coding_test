#include<bits/stdc++.h>

//c++17 version

using namespace std;
#define FA ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int n, e;
vector<vector<pair<int, int>>> arr;
vector<int> visited;

int calcDistance(int start, int dest) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, start });

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        int cost = p.first;
        int node = p.second;

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
            fill(visited.begin(), visited.end(), 0);
            return cost;
        }
    }

    fill(visited.begin(), visited.end(), 0);
    return -1;
}

int main() {
    FA;

    cin >> n >> e;
    arr.resize(n + 1);
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        arr[a].push_back({ b, c });
		arr[b].push_back({ a, c });
    }

    int pa1, pa2;
    cin >> pa1 >> pa2;

    visited.resize(n + 1, 0);

    int a = calcDistance(1, pa1);
    int b = calcDistance(pa1, pa2);
    int c = calcDistance(pa2, n);
    int d = calcDistance(1, pa2);
    int e = calcDistance(pa2, pa1);
    int f = calcDistance(pa1, n);

    int an = 1e9;

    if (!(a == -1 || b == -1 || c == -1))
    {
        an = min(an, a + b + c);
    }

    if (!(d == -1 || e == -1 || f == -1))
    {
        an = min(an, d + e + f);
    }

    if (an == 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << an;
    }


    return 0;
}