#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

char num[3] = { '1', '2', '3' };
int n;

bool check(string& ans, int i) {
	for (int k = 1; k <= ans.size() / 2; k++) {
		int right = i;
		int left = i - k;
		string left_sub = ans.substr(left - k + 1, k);
		string right_sub = ans.substr(right - k + 1, k);
		if (left_sub == right_sub) {
			return false;
		}
	}
	return true;
}

bool dfs(string& cur) {
    if (cur.size() == n) {
        cout << cur << '\n';
		return true;
    }

    for (int i = 0; i < 3; i++) {
        cur += num[i];
		if (check(cur, cur.size() - 1)) {
			bool check = dfs(cur);
			if (check) {
				return true;
			}
		}
		
		cur.pop_back();
    }

	return false;
}

int main(){ 
    FAST;

	cin >> n;
	string ans = "1";
	dfs(ans);

    return 0;
}