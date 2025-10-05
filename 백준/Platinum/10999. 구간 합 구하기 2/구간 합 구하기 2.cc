#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

class LazySegmentTree {
public:
    vector<ll> segtree, lazy;
    int size;
    void Init(vector<ll>& arr)
    {
        size = arr.size();
        segtree.resize(4 * size);
        lazy.resize(4 * size);
        Init(arr, 0, 0, size - 1);
    }
    void Init(vector<ll>& arr, int node, int start, int end)
    {
        if (start == end)
        {
            segtree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        Init(arr, 2 * node + 1, start, mid);
        Init(arr, 2 * node + 2, mid + 1, end);
        segtree[node] = segtree[2 * node + 1] + segtree[2 * node + 2];
    }
    void Update(int left, int right, ll value)
    {
        Update(0, 0, size - 1, left, right, value);
    }
    void Update(int node, int start, int end, int left, int right, ll value)
    {
        if (lazy[node] != 0)
        {
            segtree[node] += (end - start + 1) * lazy[node];
            if (start != end)
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (right < start || end < left) return;
        if (left <= start && end <= right)
        {
            segtree[node] += (end - start + 1) * value;
            if (start != end)
            {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }
        int mid = (start + end) / 2;
        Update(2 * node + 1, start, mid, left, right, value);
        Update(2 * node + 2, mid + 1, end, left, right, value);
        segtree[node] = segtree[2 * node + 1] + segtree[2 * node + 2];
    }

    ll Query(int left, int right)
    {
        return Query(0, 0, size - 1, left, right);
	}

    ll Query(int node, int start, int end, int left, int right)
    {
        if (right < start || end < left) return 0;
        if (lazy[node] != 0)
        {
            segtree[node] += (end - start + 1) * lazy[node];
            if (start != end)
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (left <= start && end <= right) return segtree[node];
        int mid = (start + end) / 2;
        ll lsum = Query(2 * node + 1, start, mid, left, right);
        ll rsum = Query(2 * node + 2, mid + 1, end, left, right);
        return lsum + rsum;
	}
};

int main() {
    FAST;

    int n, m, k; cin >> n >> m >> k;

	vector<ll> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	LazySegmentTree segtree;
	segtree.Init(arr);

    for (int i = 0; i < m + k; i++)
    {
		int a; cin >> a;
        if (a == 1)
        {
			int b, c; ll d; cin >> b >> c >> d;
            segtree.Update(b - 1, c - 1, d);
        }
        else
        {
            int b, c; cin >> b >> c;
            cout << segtree.Query(b - 1, c - 1) << '\n';
        }
    }


    return 0;
}
