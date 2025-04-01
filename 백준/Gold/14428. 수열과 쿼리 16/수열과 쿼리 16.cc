#include<bits/stdc++.h>

using namespace std;
#define FA ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int n;
pair<int, int> tree[200001];
int m;

void update(int i, int value) {
    i += n;
    tree[i].first = value;

    int cur = i / 2;
    while (cur > 0) {
        tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
        cur /= 2;
    }
}

pair<int, int> query(int l, int r) {
    l += n; r += n;

    pair<int, int> res = { 1e9, 1e9 };

    while (l <= r) {
        if (l & 1) {
            res = min(res, tree[l++]);
		}
        if (~r & 1) {
            res = min(res, tree[r--]);
		}
		l /= 2; r /= 2;
	}

    return res;
}


int main() {
    FA;

    cin >> n;

    
    fill(tree, tree + 200001, make_pair(1e9, 1e9));

    for (int i = 0; i < n; i++) {
        cin >> tree[n + i].first;
        tree[n + i].second = i;
    }

    for (int i = n - 1; i > 0; i--) {
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }

    tree[0] = tree[1];
    cin >> m;

    while (m--)
    {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            b--;
            update(b, c);
        }
        else
        {
            b--; c--;
            cout << query(b, c).second + 1 << '\n';
        }
    }

    return 0;
}