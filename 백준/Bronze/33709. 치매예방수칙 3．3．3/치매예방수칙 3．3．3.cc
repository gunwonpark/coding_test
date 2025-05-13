#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main()
{
	FAST;

	int n; cin >> n;
	string input; cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '.' || input[i] == '|' || input[i] == '#' || input[i] == ':') {
			input[i] = ' ';
		}
	}

	stringstream in(input);

	int ans = 0;
	
	while (in >> input)
	{
		ans += stoi(input);
	}

	cout << ans;

	return 0;
}

