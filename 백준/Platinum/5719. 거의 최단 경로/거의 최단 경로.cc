#include<bits/stdc++.h>

//c++17 version

using namespace std;
#define FA ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

struct Point
{
    int di, prev, cur;
    Point(int d, int p, int c) : di(d), prev(p), cur(c) {}
    Point() : Point(0, 0, 0) {}
    bool operator<(const Point& p) const
    {
		return di > p.di;
	}
};

int main() {
    FA;

    while (true)
    {
        int n, m; cin >> n >> m;

        if(n == 0 && m == 0)
			break;

        int p1, p2; cin >> p1 >> p2;

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < m; i++) {
            int u, v, p; cin >> u >> v >> p;
            adj[u].push_back({ v, p });
        }

        vector<int> dir(n, 1e9);
        vector<vector<int>> path(n);
        priority_queue<Point> pq;

        for (auto& i : adj[p1])
        {
            int next = i.first;
            int cost = i.second;

            pq.push(Point(cost, p1, next));
            dir[next] = cost;
            path[next].push_back(p1);
        }

        int min_value = -1;
        dir[p1] = 0;

        while (pq.empty() == false)
        {
            int di = pq.top().di;
            int prev = pq.top().prev;
            int cur = pq.top().cur;

            pq.pop();

            if (min_value != -1 && min_value < di)
                continue;

            if (cur == p2) {
                if (min_value == -1 || min_value == di) {
                    min_value = di;
                    continue;
                }
            }


            for (auto& i : adj[cur])
            {
                int next = i.first;
                int cost = i.second;

                if (dir[next] < di + cost)
					continue;

                if (dir[next] == di + cost )
                {
					path[next].push_back(cur);
				}
                else
                {
                    path[next].clear();
                    path[next].push_back(cur);
                    dir[next] = di + cost;
                    pq.push(Point(di + cost, cur, next));
                }
            }
        }

        vector<vector<bool>> vi(n, vector<bool>(n, false));

        queue<int> path_q;
        path_q.push(p2);
        
        while (path_q.empty() == false)
        {
            int cur = path_q.front();
			path_q.pop();

            for (auto& i : path[cur])
            {
                if(vi[i][cur] == true)
					continue;

                vi[i][cur] = true;
                path_q.push(i);
			}
        }

        for (auto& i : adj[p1])
        {
            int next = i.first;
            int cost = i.second;

            pq.push(Point(cost, p1, next));
        }

        min_value = -1;

        while (pq.empty() == false)
        {
            int di = pq.top().di;
            int prev = pq.top().prev;
            int cur = pq.top().cur;
            pq.pop();

            if (vi[prev][cur] == true)
                continue;

            vi[prev][cur] = true;

            if (cur == p2) {
                min_value = di;
                break;
            }

            for (auto& i : adj[cur])
            {
                int next = i.first;
                int cost = i.second;

                pq.push(Point(di + cost, cur, next));
            }
        }

        cout << min_value << "\n";
    }



    return 0;
}