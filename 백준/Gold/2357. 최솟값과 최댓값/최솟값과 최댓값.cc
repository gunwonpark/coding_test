#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

vector<int> arr;
vector<int> min_tree;
vector<int> max_tree;

int min_init(int start, int end, int node) {
    if(start == end) return min_tree[node] = arr[start];
    int mid = (start + end) / 2;
    return min_tree[node] = min(min_init(start, mid, node * 2), min_init(mid + 1, end, node * 2 + 1));
}

int max_init(int start, int end, int node) {
    if(start == end) return max_tree[node] = arr[start];
    int mid = (start + end) / 2;
    return max_tree[node] = max(max_init(start, mid, node * 2), max_init(mid + 1, end, node * 2 + 1));
}

void init() {
    min_init(0, arr.size() - 1, 1);
    max_init(0, arr.size() - 1, 1);
}
int min_query(int start, int end, int node, int node_left, int node_right) {
    if (start > node_right || end < node_left) return 1000000001;
    if (start <= node_left && end >= node_right) return min_tree[node];
    int mid = (node_left + node_right) / 2;
    return min(min_query(start, end, node * 2, node_left, mid), min_query(start, end, node * 2 + 1, mid + 1, node_right));
}

int max_query(int start, int end, int node, int node_left, int node_right) {
	if (start > node_right || end < node_left) return 0;
	if (start <= node_left && end >= node_right) return max_tree[node];
	int mid = (node_left + node_right) / 2;
	return max(max_query(start, end, node * 2, node_left, mid), max_query(start, end, node * 2 + 1, mid + 1, node_right));
}

pair<int, int> min_max_query(int start, int end) {
	return {min_query(start, end, 1, 0, arr.size() - 1), max_query(start, end, 1, 0, arr.size() - 1)};
}

int main() {
    FAST;
    int n, m;
    cin >> n >> m;

    arr.resize(n);
    min_tree.resize(4 * n, 1000000001);
    max_tree.resize(4 * n, 0);

    for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

    init();

    while (m--) {
        int a, b;
        cin >> a >> b;

        pair<int, int> result = min_max_query(a - 1, b - 1);

        cout << result.first << " " << result.second << '\n';
    }

    return 0;
}