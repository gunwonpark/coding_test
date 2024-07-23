#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>
#include <string>
#include <map>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;

int longestPath = 0;
vector<bool> visited;
vector<vector<pair<int, int>>> adj;

int height(int root) {
	//자식 노드 확인
	int childCount = adj[root].size();
	vector<pair<int, int>> children;	

	for (int i = 0; i < childCount; ++i){
		//방문하지 않은 노드만 확인
		if (visited[adj[root][i].first] != true) {
			visited[adj[root][i].first] = true;

			//자식 노드의 번호와 자식 노드의 높이를 저장
			children.push_back({ i, height(adj[root][i].first) });
		}
	}

	//자식 노드가 없는 경우 높이는 1로 간주
	if (children.size() == 0) {
		return 0;
	}

	vector<int> heights;

	//자식 노드의 높이와 루트노드와 자식 노드간의 거리를 더한 값을 저장
	for (auto& child : children) {
		heights.push_back(adj[root][child.first].second + child.second);
	}

	//노드의 거리를 오름차순 정렬
	sort(heights.begin(), heights.end(), greater<int>());

	//자식 노드가 2개 이상인 경우	가장 긴 두 노드의 거리를 더한 값이 가장 긴 경로가 됨
	if (children.size() >= 2) {
		longestPath = max(longestPath, heights[0] + heights[1]);
	}

	//현재 노드의 높이 값 갱신	
	return heights[0];
}

int selectNum = 1;

void dfs(int start, int cost) {

	if (visited[start]) return;

	if (longestPath < cost) {
		selectNum = start;
		longestPath = cost;
	}

	visited[start] = true;

	int childCount = adj[start].size();

	for (int i = 0; i < childCount; ++i) {
		dfs(adj[start][i].first, cost + adj[start][i].second);
	}

	return;
}

int main() {
	FAST;

	int n;
	cin >> n;

	cin.ignore();

	adj.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < n; ++i) {
		string line;
		getline(cin, line);

		stringstream ss(line);

		int node;
		ss >> node;

		int tNode, dist;
		while (ss >> tNode && tNode != -1) {
			ss >> dist;
			adj[node].push_back({ tNode, dist });
		}
	}

	longestPath = 0;

	////임의 정점에서 시작
	//longestPath = max(longestPath, height(1));

	
	dfs(selectNum, 0);
	
	visited.assign(n + 1, false);

	dfs(selectNum, 0);


	cout << longestPath;

	return 0;
}


