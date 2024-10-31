#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main() {
    Fast;
 
    int A, B, C;
    cin >> A >> B >> C;

    int digits = 1;
    while (B >= digits) {
        digits *= 10;
    }

    cout << A + B - C << '\n';
    cout << A * digits + B - C;

    
    return 0;
}