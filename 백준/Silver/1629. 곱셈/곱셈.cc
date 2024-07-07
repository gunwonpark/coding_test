#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    

    int a,b,c;
    cin >> a >> b >> c;

    ll res = a;

    vector<ll> vec(32, 0);

    for (size_t i = 0; i <vec.size(); i++)
    {
        vec[i] = res;
        res *= res;
        res %= c;
    }
    
    res = 1;

    for (int i = 0; b > 0; b >>= 1, ++i) 
    {
        if(b & 1)
        {
            res *= vec[i];
            res %= c;
        }
    }

    cout << res;

	return 0;
}


