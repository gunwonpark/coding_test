#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

string preprocess(const string& s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }
    return t;
}

int main() {
    FAST;

    string s;
    cin >> s;

    string t = preprocess(s);
    int n = t.length();
    vector<int> A(n, 0);

    int r = 0, c = 0; 
    for (int i = 0; i < n; ++i) {
        if (i < r) {
            int i_mirror = 2 * c - i;
            A[i] = std::min(r - i, A[i_mirror]);
        }

        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < n &&
            t[i - A[i] - 1] == t[i + A[i] + 1]) {
            A[i]++;
        }

        if (i + A[i] > r) {
            r = i + A[i];
            c = i;
        }
    }

    int max_len = 0;
    for (int val : A) {
        if (val > max_len) {
            max_len = val;
        }
    }

    cout << max_len << "\n";

    return 0;
}
