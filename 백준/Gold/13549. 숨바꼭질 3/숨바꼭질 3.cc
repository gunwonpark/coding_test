#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

int dp[100001] = { 0, };
bool visited[100001] = { false, };

int dir[2] = { -1, 1};

int main() {
	Fast;

	int n, k;
	cin >> n >> k;

	queue<int> s;
	s.push(n);

	while(!s.empty()) {
		int cur = s.front();
		visited[cur] = true;
		s.pop();

		int temp = cur;
		while (temp < 100001 && temp > 0) {
			if (visited[temp]) {
				temp *= 2;
				continue;
			}
			s.push(temp);
			dp[temp] = dp[cur];
			visited[temp] = true;
			temp *= 2;
		}

		

		for (int i = 0; i < 2; i++) {
			int next = cur + dir[i];

			if(next < 0 || next > 100000) continue;

			if (visited[next]) continue;

			dp[next] = dp[cur] + 1;
			visited[next] = true;
			s.push(next);
		}
	}

	cout << dp[k] << "\n";
	return 0;
	
}