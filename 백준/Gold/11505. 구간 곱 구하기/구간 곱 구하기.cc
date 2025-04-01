#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> arr;
ll mod = 1000000007;

struct Tree
{
	vector<ll> tree;
	int _n;

	Tree() {

	}
	Tree(int n) {
		Init(n);
	}
	void Init(int n) {
		_n = n;
		tree.resize(n * 4, 1);
		Init(0, n - 1, 1);
	}

	ll Init(int left, int right, int node) {
		if (left == right) return tree[node] = arr[left];
		int mid = (left + right) / 2;
		return tree[node] = (Init(left, mid, node * 2) * Init(mid + 1, right, node * 2 + 1)) % mod;
	}

	void Update(int ind, ll value) {
		Update(0, _n - 1, ind, 1, value);
	}

	ll Update(int left, int right, int ind, int node, ll value) {
		if (left > ind || right < ind) return tree[node];
		if (left == ind && right == ind) return tree[node] = value;

		int mid = (left + right) / 2;		
		return tree[node] = (Update(left, mid, ind, node * 2, value) * Update(mid + 1, right, ind, node * 2 + 1, value)) % mod;
	}

	ll Query(int left, int right) {
		return Query(0, _n - 1, left, right, 1);
	}

	ll Query(int l, int r, int left, int right, int node) {
		if (r < left || l > right) return 1;
		if (left <= l && right >= r) return tree[node];

		int mid = (l + r) / 2;

		return (Query(l, mid, left, right, node * 2) * Query(mid + 1, r, left, right, node * 2 + 1)) % mod;
	}
};



int main() {
	int n, m, k; cin >> n >> m >> k;
	arr.resize(n);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
    
	Tree t = Tree(n);

	int te = m + k;

	while (te--)
	{
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			t.Update(b - 1, c);
		}
		else
		{
			cout << t.Query(b - 1, c - 1) << '\n';
		}
	}

    return 0;
}