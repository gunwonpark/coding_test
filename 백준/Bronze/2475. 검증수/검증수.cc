#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main() {
    Fast;
 
    int result = 0;
    for (int i = 0; i < 5; i++)
    {
        int input;
        cin >> input;
        result += input * input;
    }

    cout << result % 10;
    
    return 0;
}