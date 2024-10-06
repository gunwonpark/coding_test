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

int findPrev(vector<int>& arr, vector<int>& table, int index) {
	int result = -1;
	int m = 0;
	for (int i = index - 1; i >= 0; i--) {
		if (arr[index] > arr[i]) {
			if (table[i] > m) {
				m = table[i];
				result = i;
			}
		}
	}

	if(result != -1)
		return result;
	else
		return -1;
}

int main() {
	Fast;

	int n;
	cin >> n;

	vector<vector<int>> arr(n + 1);
	vector<int> visited(n + 1, 0);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		arr[b].push_back(a);
		arr[a].push_back(b);
	}

	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();		

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i];
			if (visited[next]) continue;

			visited[next] = cur;
			q.push(next);
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << visited[i] << '\n';
	}
	
	return 0;
	
}