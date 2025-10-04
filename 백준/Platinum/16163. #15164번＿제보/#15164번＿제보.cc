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
        if (i < r)
        {
            int mirror = 2 * c - i;
            A[i] = min(A[mirror], r - i);
        }

        while(i + A[i] + 1 < n && i - A[i] - 1 >= 0 && t[i + A[i] + 1] == t[i - A[i] - 1]) {
            A[i]++;
		}

        if (i + A[i] > r)
        {
            c = i;
            r = i + A[i];
        }
    }
    ll answer = 0;
    for (int& x : A)
    {
        answer += (x + 1) / 2;
    }

    cout << answer << "\n";

    return 0;
}
