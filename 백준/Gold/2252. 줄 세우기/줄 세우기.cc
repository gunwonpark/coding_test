#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;

vector<vector<int>> arr;
vector<int> inDegree;
queue<int> q;

int main() {
	FAST;

	int N, M;
	cin >> N >> M;
	
	arr.resize(N + 1);
	inDegree.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		inDegree[b]++;
	}

	for (int i = 1; i < N + 1; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	for(int i = 1; i < N + 1; i++){
		if (q.empty()) {
			cout << "cycle" << endl;
			return 0;
		}
		int index = q.front();
		q.pop();

		cout << index << " ";

		for (int i = 0; i < arr[index].size(); i++) {
			int next = arr[index][i];
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
	

	return 0;
}


