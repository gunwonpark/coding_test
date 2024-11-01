#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main() {
    Fast;
    int n;
    cin >> n;
 
    while (n--) {
        string s;
        cin >> s;

        stack<char> st;
        bool can = true;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push('(');
            }
            else if (s[i] == ')') {
                if (st.empty() || st.top() != '(') {
                    can = false;
                    break;
                }
                st.pop();
            }
        }

        if (can && st.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}