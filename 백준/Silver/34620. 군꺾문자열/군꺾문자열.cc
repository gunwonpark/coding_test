#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;


int main() {
    FAST;

    int a, b; cin >> a >> b;
    vector<char> result;
    
    int temp = b;
    while ((temp & 1) == 0)
    {
        temp >>= 1;
    }

    if (temp != 1)
    {
        cout << -1;
        return 0;
    }

    int left = a / b;
	a -= left * b;

    result.push_back('G');
    for (int i = 2; i <= b; i *= 2)
    {
        result.push_back('K');
		if(a & i)
			result.push_back('G');
    }

    for(int i = 0; i < left; i++)
		result.push_back('G');

    for (char c : result)
		cout << c;

    return 0;
}
