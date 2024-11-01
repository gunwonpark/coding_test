#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main() {
    Fast;
    int n;
    cin >> n;

    stack<int> st;
    while (n--) {
        string s;
        
        cin >> s;

        if (s == "push") {
            int input;
            cin >> input;
            st.push(input);
        }
        else if (s == "top") {
            if (st.empty()) cout << -1 << '\n';
            else cout << st.top() << '\n';
        }
        else if (s == "size") {
            cout << st.size() << '\n';
        }
        else if (s == "empty") {
            cout << st.empty() << '\n';
        }
        else if (s == "pop") {
            if (st.empty()) cout << -1 << '\n';
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
    }
    
    return 0;
}