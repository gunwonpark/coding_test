#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

//0 ~ 2000

vector<int> dp;
vector<tuple<int, int, ll>> points;


int dfs(int i, int s)
{
    int x = get<0>(points[i]);
    int y = get<1>(points[i]);
    ll curt = get<2>(points[i]);

    if (dp[i] != -1)
        return dp[i];

	int maxDepth = 0;

    for (int j = i + 1; j < points.size(); j++)
    {
        int nextx = get<0>(points[j]);
        int nexty = get<1>(points[j]);
        ll nextt = get<2>(points[j]);
        ll enableTime = (nextt - curt) * s;
        ll sqrtDist = (ll)(nextx - x) * (ll)(nextx - x) + (ll)(nexty - y) * (ll)(nexty - y);

        if (sqrtDist <= enableTime * enableTime) {
            maxDepth = max(maxDepth, dfs(j, s));
        }
    }
    
	return dp[i] = maxDepth + 1;
}

int main() {
    FAST;

    int n, s; cin >> n >> s;
    dp.resize(n + 1, -1);

    for(int i = 0; i < n; i++) {
        int x, y; ll t; cin >> x >> y >> t;
        points.push_back({ x + 1000, y + 1000, t });
	}

    points.push_back({ 1000, 1000, 0 });

    sort(points.begin(), points.end(), [](const tuple<int, int, ll>& a, const tuple<int, int, ll>& b) {
        return get<2>(a) < get<2>(b);
		});

	int result = 0;
    
    int temp = dfs(0, s);
	result = max(result, temp);
   

	cout << result - 1 << "\n";

    return 0;
}
