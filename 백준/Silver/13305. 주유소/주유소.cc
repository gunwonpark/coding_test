#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

int main() {
    FAST;

    int n;

    cin >> n;
    
    vector<int> dist(n - 1);
    vector<int> city(n);

    for (int i = 0; i < n - 1; i++) {
		cin >> dist[i];
	}

    for (int i = 0; i < n; i++) {
        cin >> city[i];
    }

    ll sum = 0;

    ll cur = city[0];
    for (int i = 0; i < n - 1; i++) {
        if (cur > city[i]) {
			cur = city[i];
		}

        sum += cur * dist[i];
    }

    cout << sum;
    return 0;
}