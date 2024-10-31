#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main() {
    Fast;
 
    int T;
    cin >> T;
    int y_adder = 100000001;
    int x_adder = 1;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;

            cout << i + 1 << " " << x + x_adder << " " << y + y_adder << '\n';
        }
    }
    
    
    return 0;
}