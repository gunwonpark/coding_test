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

int n;

vector<bool> visited;
vector<int> adj;

int main() {
	Fast;

	cin >> n;

	visited.resize(n + 1, false);
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> adj[i];
	}

	ll result = 0;
	vector<int> result_list;

	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		vector<int> temp;
		temp.push_back(i);

		int next = adj[i];

		while (!visited[next]) {
			visited[next] = true;
			temp.push_back(next);
			next = adj[next];
		}

		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == next) {
				result_list.insert(result_list.end(), temp.begin() + i, temp.end());
				result += temp.size() - i;
				break;
			}
		}
	}

	cout << result << '\n';

	sort(result_list.begin(), result_list.end());

	for(int i = 0; i < result_list.size(); i++)
		cout << result_list[i] << '\n';

	return 0;
	
}