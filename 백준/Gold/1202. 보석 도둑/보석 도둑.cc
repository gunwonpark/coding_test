#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

struct info {
    int weight, value;

    bool operator < (const info& b) const {
        return weight < b.weight;
    }
};

vector<info> jewels;
vector<int> bags;
vector<pair<int, int>> max_tree;

pair<int, int> init(int start, int end, int node) {
    if (start == end) return max_tree[node] = { jewels[start].value, start };
    int mid = (start + end) / 2;
    return max_tree[node] = max(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

pair<int, int> query(int start, int end, int node, int nodeLeft, int nodeRight) {
    if (start > nodeRight || end < nodeLeft) return { -1, -1 };
    if (start <= nodeLeft && end >= nodeRight) return max_tree[node];
    int mid = (nodeLeft + nodeRight) / 2;
    return max(query(start, end, node * 2, nodeLeft, mid), query(start, end, node * 2 + 1, mid + 1, nodeRight));
}
pair<int, int> update(int index, int value, int node, int nodeLeft, int nodeRight) {
    if (index < nodeLeft || index > nodeRight) return{ max_tree[node].first, max_tree[node].second };
    if (nodeLeft == nodeRight) return{ max_tree[node].first = value, max_tree[node].second };
    int mid = (nodeLeft + nodeRight) / 2;
    return max_tree[node] = max(update(index, value, node * 2, nodeLeft, mid), update(index, value, node * 2 + 1, mid + 1, nodeRight));
}

int main() {
    Fast;

    int n, k;
    cin >> n >> k;

    jewels.resize(n);
    bags.resize(k);
    max_tree.resize(4 * n);

    for (int i = 0; i < n; i++) {
        cin >> jewels[i].weight >> jewels[i].value;
    }

    for (int i = 0; i < k; i++) {
        cin >> bags[i];
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    init(0, n - 1, 1);

    ll result = 0;

    for (int i = 0; i < k; i++) {
        int limit = bags[i];
        //limit을 넘지 않는 가장 큰 인덱스
        int index = upper_bound(jewels.begin(), jewels.end(), limit, [](int limit, const info& jewel) {
            return limit < jewel.weight;
            }) - jewels.begin() - 1;

            if (index < 0) continue;

            pair<int, int> q = query(0, index, 1, 0, n - 1);
            if (q.first == -1) continue;

            result += q.first;
            update(q.second, -1, 1, 0, n - 1);
    }

    cout << result;

    return 0;
}