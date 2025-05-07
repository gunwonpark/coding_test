#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int n;
vector<pair<int, int>> eggs;
vector<int> disapear;
int answer = 0;

void dfs(int cur) {
	if (cur == n) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (disapear[i] == 1) {
				count++;
			}
		}
		answer = max(answer, count);
		return;
	}

	if (disapear[cur] == 1) {
		dfs(cur + 1);
		return;
	}

	bool isHit = false;

	for (int i = 0; i < n; i++) {
		if (disapear[i] == 1 || i == cur) continue;

		isHit = true;

		int curEgg = eggs[cur].first;
		int curEggPower = eggs[cur].second;
		int nextEgg = eggs[i].first;
		int nextEggPower = eggs[i].second;
		
		curEgg -= nextEggPower;
		nextEgg -= curEggPower;

		if (curEgg <= 0) {
			disapear[cur] = 1;
		}

		if (nextEgg <= 0) {
			disapear[i] = 1;
		}

		eggs[cur].first = curEgg;
		eggs[i].first = nextEgg;

		dfs(cur + 1);

		curEgg += nextEggPower;
		nextEgg += curEggPower;

		if (curEgg > 0) {
			disapear[cur] = 0;
		}

		if (nextEgg > 0) {
			disapear[i] = 0;
		}

		eggs[cur].first = curEgg;
		eggs[i].first = nextEgg;
	}

	if (isHit == false) {
		dfs(cur + 1);
	}
}

int main(){ 
    FAST;
    cin >> n;
	disapear.resize(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		eggs.push_back({ a, b });
	}
    
	
	dfs(0);	
	
   
	cout << answer << "\n";
    return 0;
}