#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;

    bool isPalindrome = true;
    bool isAllSame = true;

    string s; cin >> s;

	char firstChar = s[0];
	
    for(int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            isPalindrome = false;
        }
        if (s[i] != firstChar) {
            isAllSame = false;
        }
	}

    for(int i = s.length() / 2; i < s.length(); i++) {
        if (s[i] != firstChar) {
            isAllSame = false;
        }
	}

    if (isAllSame)
    {
        cout << -1;
    }
    else if (isPalindrome)
    {
        cout << s.length() - 1;
    }
    else
    {
        cout << s.length();
	}


    return 0;
}
