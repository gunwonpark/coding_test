#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#define inf 987654321
#define ntimes(n, x) for(int x=0;x<n;x++)
#define forall(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple <int, int, int>;


long long seg[2000100];

long long numlist[505000];
long long blocklist[505000];
long long lmax[505000];
long long rmax[505000];
pair<long long, char> border[505000];
int n, t;
string yklist;

int segad;


long long sum(int l, int r) {
    long long res = 0;
    l += segad; r += segad;
    while (l <= r) {
        if (l % 2)
            res += seg[l++];
        if (!(r % 2))
            res += seg[r--];
        l >>= 1; r >>= 1;
    }
    return res;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin >> yklist;


    cin >> numlist[0];
    border[0].first = 0;
    border[0].second = yklist[0];
    int bpos = 0;
    int mmax = numlist[0];
    vector<int> maxlist;


    for (int i = 1; i < n; i++) {
        cin >> numlist[i];
        if (border[bpos].second != yklist[i]) {
            border[++bpos].first = i;
            border[bpos].second = yklist[i];
            maxlist.push_back(mmax);
            mmax = numlist[i];
        }
        else {
            if (mmax < numlist[i])
                mmax = numlist[i];

        }
        lmax[i] = mmax;
        blocklist[i] = bpos;
    }
    bpos++;
    border[bpos].first = n;
    maxlist.push_back(mmax);

    int j = n - 1;
    for (int i = bpos - 1; i >= 0; i--) {
        int mmax = 0;
        while (j >= border[i].first) {
            if (mmax < numlist[j])  mmax = numlist[j];
            rmax[j] = mmax;
            j--;
        }
    }

    segad = 1;
    while (segad < bpos) segad *= 2;

    for (int i = 0; i < maxlist.size(); i++) {
        seg[segad + i] = maxlist[i];
    }

    for (int i = segad - 1; i > 0; i--) {
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }

    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int lb = -1; int rb = -1;
        lb = blocklist[l];
        rb = blocklist[r];
        int yf = 1; int kf = 1;

        long long ysum = 0; int yl = lb; int yr = rb;
        long long ksum = 0; int kl = lb; int kr = rb;

        if (lb == rb) {
            cout << "YK " << 0 << "\n";
            continue;
        }
        if (rb - lb == 1) {
            if (border[lb].second == 'Y') {
                cout << "Y " << rmax[l] + lmax[r] << "\n";
            }
            else {
                cout << "K " << rmax[l] + lmax[r] << "\n";
            }
            continue;
        }

        if (border[lb].second == 'Y') {
            kl++;
            if (l != border[lb].first) {
                ysum += rmax[l];
                yl++;
            }
        }
        else {
            yl++;
            if (l != border[lb].first) {
                ksum += rmax[l];
                kl++;
            }
        }
        if (border[rb].second == 'Y') {
            yr--;
            if (r != border[rb + 1].first - 1) {
                ksum += lmax[r];
                kr--;
            }
        }
        else {
            kr--;
            if (r != border[rb + 1].first - 1) {
                ysum += lmax[r];
                yr--;
            }
        }
        if (yf) ysum += sum(yl, yr);
        if (kf) ksum += sum(kl, kr);
        if (ysum > ksum) {
            cout << "Y " << ysum << "\n";
        }
        else if (ysum < ksum) {
            cout << "K " << ksum << "\n";
        }
        else {
            cout << "YK " << ysum << "\n";
        }
    }
    return 0;
}