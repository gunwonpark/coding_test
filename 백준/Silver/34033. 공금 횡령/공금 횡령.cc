#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;



int main()
{
	FAST;

	int n, m;
	cin >> n >> m;

	map<string, int> ma;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int input; cin >> input;

		ma[s] = input * 100 + input * 5;
	}

	int result = 0;

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		int input; cin >> input;

		if (ma[s] < input * 100) {
			result++;
		}
	}

	cout << result;
	return 0;
}

