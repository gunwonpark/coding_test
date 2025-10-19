#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;
    vector<ll> values;
    vector<int> rockPos;
    vector<int> targetPos;

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int val; cin >> val;
		rockPos.push_back(val);
	}
    for (int i = 0; i < n; i++) {
		int val; cin >> val;
		targetPos.push_back(val);
    }

	for (int i = 0; i < n; i++) {
        values.push_back(rockPos[i] - targetPos[i]);
    }

    vector<ll> calcValues;
	calcValues.push_back(values[0]);
    for (int i = 1; i < n; i++)
    {
        calcValues.push_back(values[i] - values[i - 1]);
    }
	calcValues.push_back(-values[n - 1]);
    
    ll result = 0;
   
    for (ll val : calcValues) {
        if(val > 0)
            result += val;
	}

	cout << result << "\n";

    return 0;
}
