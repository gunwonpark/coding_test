#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

typedef long long ll;

int main() {
    FAST;

    int Q;
    cin >> Q;

    string find_str = "ABB";
    string replace_str = "BA";
    while (Q--) {
        int len;
        cin >> len;

        string s;
        cin >> s;

        stack<pair<char, int>> st;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'A') {
                st.push({ 'A', 0 });
            }
            else {
                if (!st.empty()) {
                    if (st.top().second == 0) {
                        st.push({ 'B' , 1 });
                    }
                    else if (st.top().second == -1) {
                        st.push({ 'B', -1 });
                    }
                    else {
                        st.push({ 'B', 2 });
                    }
                }
                else {
                    st.push({ 'B', -1 });
                }
            }

            //제거 시작
            int count = 0;
            if(!st.empty() && st.top().second == 2) {
                st.pop();
                st.pop();
                st.pop();
                count++;

                while(!st.empty() && st.top().second == 1) {
                    st.pop();
                    st.pop();
                    count++;
                }

                if (st.empty() || st.top().second == -1) {
                    st.push({ 'B', -1 });
                }
                else {
                    st.push({ 'B', 1 });
                }

                while (count--) {
                    st.push({ 'A', 0 });
                }
                
            }
        }

        string answer;
        while (!st.empty()) {
            answer.push_back(st.top().first);
            st.pop();
        }

        reverse(answer.begin(), answer.end());

        cout << answer << '\n';
    }

    return 0;
}