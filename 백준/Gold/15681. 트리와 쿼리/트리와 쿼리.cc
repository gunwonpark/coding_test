#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

void dfs(vector<vector<int>>& tree, vector<int>& tree_size, int cur_node)
{
    tree_size[cur_node] = 1;
    for (int i = 0; i < tree[cur_node].size(); i++) {
        int next_node = tree[cur_node][i];
        // 이미 방문한 노드 재방문 방지
        if(tree_size[next_node] != 0) continue;
        dfs(tree, tree_size, next_node);
        tree_size[cur_node] += tree_size[next_node];
    }
}

int main() {
    FAST;

    int node_count, root_number, query_count;
    cin >> node_count >> root_number >> query_count;

    vector<vector<int>> tree(node_count + 1);
    vector<int> tree_size(node_count + 1, 0);

    for (int i = 0; i < node_count - 1; i++)
    {
		int parent, child;
		cin >> parent >> child;
		tree[parent].push_back(child);
        tree[child].push_back(parent);
	}

    dfs(tree, tree_size, root_number);

    for (int i = 0; i < query_count; i++)
    {
		int query;
		cin >> query;
		cout << tree_size[query] << "\n";
	}

    return 0;
}