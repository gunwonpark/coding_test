#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

int main() {
    FAST;
    int n; cin >> n;
    string s; cin >> s;

    int answer = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (s[i] == '1') {
            while (i >= 1 && s[i] == '1') {
                i--;
            }
			s[i] = '1';
            i++;
            answer++;
        }
    }

    cout << answer;
    return 0;
}