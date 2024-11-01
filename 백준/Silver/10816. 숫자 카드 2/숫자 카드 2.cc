#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main() {
    Fast;
    int n;
    cin >> n;
 
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        m[input]++;
    }

    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        int input;
        cin >> input;

        if (m.find(input) != m.end()) {
            cout << m[input] << " ";
        }
        else {
            cout << 0 << " ";
        }
    }
    
    return 0;
}