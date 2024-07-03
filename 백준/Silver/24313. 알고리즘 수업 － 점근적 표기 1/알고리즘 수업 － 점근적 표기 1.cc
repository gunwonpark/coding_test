#include <iostream>


#define ll long long

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    

    int a, b;
    int c, n;
    cin >> a >> b;
    cin >> c;
    cin >> n;

    if ((a - c) * n + b <= 0 and a - c <= 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }
    

    return 0;
}



