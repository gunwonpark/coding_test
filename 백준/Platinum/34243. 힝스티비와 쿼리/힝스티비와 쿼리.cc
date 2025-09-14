#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string s;

// v[i] : value of pattern centered at i (i from 0..n-1), nonzero only if 1 <= i <= n-2
vector<int> v;
vector<int> pref; // prefix sum of v: pref[i] = sum_{j=0..i} v[j]

// compute v and pref
void build_prefix() {
    v.assign(n, 0);
    for (int i = 1; i <= n-2; ++i) {
        if (s[i-1] == '+' && s[i] == '^' && s[i+1] == '+') v[i] = 1;
        else if (s[i-1] == '-' && s[i] == '^' && s[i+1] == '-') v[i] = -1;
    }
    pref.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        pref[i] = (i? pref[i-1] : 0) + v[i];
    }
}

// get sum of v for centers in [L, R] inclusive, safe if L>R returns 0
int getVsumRange(int L, int R) {
    if (L > R) return 0;
    L = max(L, 0);
    R = min(R, n-1);
    if (L == 0) return pref[R];
    return pref[R] - pref[L-1];
}

// compute the score of a small string (vector<char>) by scanning centers
int scoreOfWindow(const vector<char>& w) {
    int m = (int)w.size();
    int sc = 0;
    for (int i = 1; i <= m-2; ++i) {
        if (w[i-1] == '+' && w[i] == '^' && w[i+1] == '+') sc += 1;
        else if (w[i-1] == '-' && w[i] == '^' && w[i+1] == '-') sc -= 1;
    }
    return sc;
}

// compute delta_full[k]: net change (newSum - oldSum) when deleting s[k] in the whole string
int compute_delta_full_at(int k) {
    int a = max(0, k-2);
    int b = min(n-1, k+2);
    // oldSum: sum v[j] for centers j in [a+1, b-1]
    int oldSum = getVsumRange(a+1, b-1);
    // build window
    vector<char> w;
    for (int i = a; i <= b; ++i) w.push_back(s[i]);
    // remove position (k - a)
    int pos = k - a;
    vector<char> w2;
    for (int i = 0; i < (int)w.size(); ++i) if (i != pos) w2.push_back(w[i]);
    int newSum = scoreOfWindow(w2);
    return newSum - oldSum;
}

// segment tree for maxima
struct SegTree {
    int n;
    vector<int> st;
    SegTree() {}
    SegTree(int _n) { init(_n); }
    void init(int _n) {
        n = 1; while (n < _n) n <<= 1;
        st.assign(2*n, INT_MIN/2);
    }
    void build(const vector<int>& arr) {
        init((int)arr.size());
        for (int i = 0; i < (int)arr.size(); ++i) st[n+i] = arr[i];
        for (int i = n-1; i >= 1; --i) st[i] = max(st[2*i], st[2*i+1]);
    }
    // query max on [l, r] inclusive
    int query(int l, int r) {
        if (l > r) return INT_MIN/2;
        l += n; r += n;
        int res = INT_MIN/2;
        while (l <= r) {
            if (l & 1) res = max(res, st[l++]);
            if (!(r & 1)) res = max(res, st[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = (int)s.size();
    build_prefix();

    // precompute delta_full for every k
    vector<int> delta_full(n, 0);
    for (int k = 0; k < n; ++k) delta_full[k] = compute_delta_full_at(k);

    SegTree seg;
    seg.build(delta_full);

    auto getBaseSum = [&](int L, int R)->int {
        // sum v for centers in [L+1, R-1]
        if (R - L + 1 < 3) return 0;
        return getVsumRange(L+1, R-1);
    };

    auto delta_when_delete_in_substring = [&](int delPos, int L, int R)->int {
        // simulate only on local window clipped to [L,R]
        int a = max(L, delPos - 2);
        int b = min(R, delPos + 2);
        if (a > b) return 0;
        // oldSum: sum v[j] for centers j in [a+1, b-1], but those j must be within [L+1, R-1] as well
        int oldSum = getVsumRange(max(a+1, L+1), min(b-1, R-1));
        // build local window
        vector<char> w;
        for (int i = a; i <= b; ++i) w.push_back(s[i]);
        int pos = delPos - a;
        vector<char> w2;
        for (int i = 0; i < (int)w.size(); ++i) if (i != pos) w2.push_back(w[i]);
        // compute newSum but only count centers whose triplet is entirely inside [a,b] after deletion
        // however these correspond to centers in the new small window at indices 1..m-2.
        int newSum = scoreOfWindow(w2);
        return newSum - oldSum;
    };

    int Q;
    cin >> Q;
    while (Q--) {
        int l, r; cin >> l >> r;
        --l; --r;
        int baseSum = getBaseSum(l, r);
        int len = r - l + 1;
        int bestDelta = 0; // at least 0 (no deletion)
        if (len < 5) {
            // small: try every deletion position in [l,r] by simulating on substring
            for (int k = l; k <= r; ++k) {
                // build substring T = s[l..r]
                string T = s.substr(l, len);
                int idx = k - l;
                string U = T.substr(0, idx) + T.substr(idx+1);
                // compute score of U
                int sc = 0;
                for (int i = 1; i <= (int)U.size()-2; ++i) {
                    if (U[i-1] == '+' && U[i] == '^' && U[i+1] == '+') sc += 1;
                    else if (U[i-1] == '-' && U[i] == '^' && U[i+1] == '-') sc -= 1;
                }
                int delta = sc - baseSum;
                bestDelta = max(bestDelta, delta);
            }
        } else {
            // long: interior deletions [l+2, r-2] can use precomputed delta_full
            int Lint = l + 2, Rint = r - 2;
            int interiorMax = seg.query(Lint, Rint);
            bestDelta = max(bestDelta, interiorMax);
            // boundary candidates: l, l+1, r-1, r
            vector<int> candidates = {l, l+1, r-1, r};
            for (int k : candidates) {
                if (k < l || k > r) continue;
                int delta = delta_when_delete_in_substring(k, l, r);
                bestDelta = max(bestDelta, delta);
            }
        }
        // deletion optional
        if (bestDelta < 0) bestDelta = 0;
        cout << (baseSum + bestDelta) << '\n';
    }

    return 0;
}