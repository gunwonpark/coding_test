#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main() {
    Fast;
 
    while (true) {
        string s;
        cin >> s;

        if (s == "0") break;

        bool is_palindrome = true;
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                cout << "no" << '\n';
                is_palindrome = false;
                break;
            }
        }

        if (is_palindrome) {
            cout << "yes\n";
        }
    }
   
    
    return 0;
}