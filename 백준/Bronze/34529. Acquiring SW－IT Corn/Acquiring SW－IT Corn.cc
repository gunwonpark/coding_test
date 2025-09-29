#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;


int main() {
    FAST;

    int x, y, z;
	cin >> x >> y >> z;
    int u, v, w;
	cin >> u >> v >> w;


    int answer = 0;
    answer += u / 100 * x;
	answer += v / 50 * y;
	answer += w / 20 * z;
    
    cout << answer;


    return 0;
}
