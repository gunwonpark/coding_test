#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

vector<int> dist(100001, -1);

int getNext1(int x) {
	if (x + 1 >= 100000) return -1;
    return x + 1;
}

int getNext2(int x)
{
    int temp = x * 2;
    if (temp >= 100000) return -1;

    if (temp >= 10000) return temp - 10000;
    else if(temp >= 1000) return temp - 1000;
    else if(temp >= 100) return temp - 100;
    else if(temp >= 10) return temp - 10;
	else if (temp >= 1) return temp - 1;

    return temp;
}
    

int main() {
    FAST;
	int n, t, g; cin >> n >> t >> g;

    queue<pair<int, int>> q;
	q.push({ n, 0 });
	dist[n] = 0;

    while (!q.empty()) {
        int cur = q.front().first;
        int time = q.front().second;

        q.pop();

        int next1 = getNext1(cur);
        int next2 = getNext2(cur);

        if (next1 != -1 && dist[next1] == -1) {
            dist[next1] = time + 1;
            q.push({ next1, time + 1 });
		}

        if (next2 != -1 && dist[next2] == -1) {
            dist[next2] = time + 1;
            q.push({ next2, time + 1 });
        }
    }

    if (dist[g] != -1 && dist[g] <= t) {
        cout << dist[g] << '\n';
    }
    else {
        cout << "ANG" << '\n';
	}
    

    return 0;
}
