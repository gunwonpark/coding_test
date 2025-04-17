#include<bits/stdc++.h>

//c++17 version

using namespace std;
#define FA ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int check[100001];

vector<vector<int>> adj;

// childCount, parent
map<int, pair<int, int>> an;

void dfs(int a) {
    if(check[a] == 1)
		return;
    check[a] = 1;

    for (int i = 0; i < adj[a].size(); i++) {
        int b = adj[a][i];
        if (check[b] == true) continue;
        an[a].first++;
		an[b].second = a;
		dfs(b);
	}
}

int main() {
    FA;

    int n; cin >> n;

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
        adj[b].push_back(a);
	}

    dfs(1);

    stack<int> st;
    int start; cin >> start;

    st.push(start);
    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        int top = st.top();
        if (an[a].second == top) {
            st.push(a);
            an[top].first--;
            continue;
        }

        if (an[top].first != 0) {
            cout << 0;
            return 0;
        }

        while (st.size() > 0) {
			int top2 = st.top();
            if (an[top2].first == 0) {
			    st.pop();
			}
            else
            {
                if (an[a].second == top2) {
                    st.push(a);
                    an[top2].first--;
                    break;
                }
                else {
					cout << 0;
					return 0;
				}
            }
		}

        if (st.size() == 0) {
			cout << 0;
			return 0;
		}
	}

    cout << 1;
	
    return 0;
}