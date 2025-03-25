#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
	while (n--)
	{
		int a, b, c; cin >> a >> b >> c;
		int an = 0;
		
		an += min(b, c);
		an += a;
		an -= 1;
		cout << an << '\n';
	}

    return 0;
}