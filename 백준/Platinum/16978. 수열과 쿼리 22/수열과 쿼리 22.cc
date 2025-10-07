#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

class SegTree
{
public:
    vector<ll> tree;
    int size;
    void Init(vector<int>& arr)
    {
        size = arr.size();
		tree.resize(size * 4);
        Init(0, 0, size - 1, arr);
    }

    ll Init(int node, int start, int end, vector<int>& arr)
    {
        if (start == end) return tree[node] = arr[start];

		int mid = (start + end) / 2;
		ll left = Init(node * 2 + 1, start, mid, arr);
		ll right = Init(node * 2 + 2, mid + 1, end, arr);
        return tree[node] = left + right;
	}

    void Update(int index, int value)
    {
		Update(0, 0, size - 1, index, value);
    }

    ll Update(int node, int start, int end, int index, int value)
    {
        if (index < start || index > end) return tree[node];
        if (start == end)
        {
            return tree[node] = value;
        }

		int mid = (start + end) / 2;
		ll left = Update(node * 2 + 1, start, mid, index, value);
        ll right = Update(node * 2 + 2, mid + 1, end, index, value);
		return tree[node] = left + right;
    }

    ll Query(int left, int right)
    {
        return Query(0, 0, size - 1, left, right);
	}

    ll Query(int node, int start, int end, int left, int right)
    {
        if (right < start || left > end) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        ll lsum = Query(node * 2 + 1, start, mid, left, right);
        ll rsum = Query(node * 2 + 2, mid + 1, end, left, right);
        return lsum + rsum;
    }
};

struct Node {
    int k, l, r, index;
    ll sum = 0;
	Node(int _k, int _l, int _r, int _index) : k(_k), l(_l), r(_r), index(_index) {}
	Node() : k(0), l(0), r(0), index(0) {}
};

bool cmp1(const Node &a, const Node &b) {
    return a.k < b.k;
}

bool cmp2(const Node &a, const Node &b) {
    return a.index < b.index;
}

vector<pair<int, int>> querys1;
vector<Node> querys2;


int main() {
    FAST;

    int n; cin >> n;
    vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	SegTree segtree;
	segtree.Init(arr);

	int q; cin >> q;
    for(int i = 0; i < q; i++) {
		int method; cin >> method;

        if (method == 1)
        {
            int index, value; cin >> index >> value;
			querys1.push_back({ index - 1, value });
        }
        else if (method == 2)
        {
            int k, l, r; cin >> k >> l >> r;
            querys2.push_back(Node(k, l - 1, r - 1, i));
        }
	}

	sort(querys2.begin(), querys2.end(), cmp1);
	
    int current_update = 0;

    for(int i = 0; i < querys2.size(); i++) {
		int k = querys2[i].k;

        while (current_update < k)
        {
			segtree.Update(querys1[current_update].first, querys1[current_update].second);
            current_update++;
        }

		querys2[i].sum = segtree.Query(querys2[i].l, querys2[i].r);
	}

	sort(querys2.begin(), querys2.end(), cmp2);
	
	for (int i = 0; i < querys2.size(); i++) {
		cout << querys2[i].sum << "\n";
	}

    return 0;
}
