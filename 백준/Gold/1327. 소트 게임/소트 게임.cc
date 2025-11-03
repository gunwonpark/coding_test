#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

set<string> st;
int n, k;
string target;
int answer = 1e9;
void solve()
{
	queue<pair<string, int>> q;
    string start = target;
    sort(target.begin(), target.end());

	q.push({ start, 0 });

    while (!q.empty())
    {
		string s = q.front().first;
		int depth = q.front().second;
		q.pop();

        if (s == target)
        {
            answer = min(answer, depth);
            continue;
        }

        if (st.find(s) != st.end()) continue;
        st.insert(s);

        for (int i = 0; i < s.size() - k + 1; i++)
        {
            string next = s;
            reverse(next.begin() + i, next.begin() + i + k);
			q.push({ next, depth + 1 });
        }
    }
}

int main() {
    FAST;
	cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        target += c;
	}

    solve();


    if(answer == 1e9) cout << -1;
	else cout << answer;
    return 0;
}
