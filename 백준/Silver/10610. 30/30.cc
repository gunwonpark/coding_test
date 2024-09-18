#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

int main() {    
	string s;
	cin >> s;

	bool hasZero = false;
	int result = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			hasZero = true;
		}
		result += s[i] - '0';
	}

	
	if (hasZero && result % 3 == 0)
	{
		sort(s.begin(), s.end(), greater<char>());
		cout << s;
	}
	else {
		cout << -1;
	}

    return 0;
}